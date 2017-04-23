#include "light/PointLight.h"
#include "scene/Scene.h"

const vec3 PointLight::DEFAULT_FALL_OFF = vec3(0, 0, 1);
const vec3 PointLight::DEFAULT_POSITION = vec3(0, 0, 0);

float PointLight::calcBrightness(const float dist) const {
    return intensity / (fallOff.x + fallOff.y * dist + fallOff.z * dist * dist);
}

PointLight::PointLight() : Light() {
    setPosition(DEFAULT_POSITION);
    setFallOff(DEFAULT_FALL_OFF);
}

PointLight::PointLight(const Color color) : Light(color) {
    setPosition(DEFAULT_POSITION);
    setFallOff(DEFAULT_FALL_OFF);
}

PointLight::PointLight(const Color color, const vec3 position) : Light(color) {
    setColor(color);
    setPosition(position);
    setFallOff(DEFAULT_FALL_OFF);
}

vec3 PointLight::getPosition() const {
    return position;
}

void PointLight::setPosition(const vec3 position) {
    this->position = position;
}

vec3 PointLight::getFallOff() const {
    return fallOff;
}

void PointLight::setFallOff(const vec3 fallOff) {
    this->fallOff = fallOff;
}

float PointLight::getBrightness(const Scene & scene, const Intersection & intersection) const {
    
    // Setup basic parameters
    vec3 diff = position - intersection.getPosition();
    float dist = sqrt(dot(diff, diff));
    
    // Check if the light cast shadow
    if (castShadow) {
        
        Ray ray = Ray(intersection.getPosition(), diff);
        ray.increment(intersection.getNormal()); // Must do to avoid floating point
        Intersection barrier = Intersection(ray);
        
        // Check shadow
        if (scene.getIntersection(ray, barrier) && barrier.getDistanceToOrigin() < dist) {
            return 0;
        }
    }
    
    // If not cast shadow or no shadow, return the normal brightness
    return calcBrightness(dist);
}

vec3 PointLight::getToLightDirection(const Intersection & intersection) const {
    return normalize(position - intersection.getPosition());
}
