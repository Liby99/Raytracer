#include "light/PointLight.h"

PointLight::DEFAULT_FALL_OFF = vec3(0, 0, 1);
PointLight::DEFAULT_POSITION = vec3(0, 0, 0);

float calcBrightness(float distance) {
    return intensity / (fallOff.x + fallOff.y * dist + fallOff.z * dist * dist);
}

PointLight::PointLight() : Light() {
    setPosition(DEFAULT_POSITION);
    setFallOff(DEFAULT_FALL_OFF);
}

PointLight::PointLight(Color color) : Light(color) {
    setPosition(DEFAULT_POSITION);
    setFallOff(DEFAULT_FALL_OFF);
}

PointLight::PointLight(Color color, vec3 position) : Light(color) {
    setColor(color);
    setPosition(position);
    setFallOff(DEFAULT_FALL_OFF);
}

vec3 PointLight::getPosition() {
    return position;
}

void PointLight::setPosition(vec3 position) {
    this->position = position;
}

vec3 PointLight::getFallOff() {
    return fallOff;
}

void PointLight::setFallOff(vec3 fallOff) {
    this->fallOff = fallOff;
}

float getBrightness(Scene & scene, Intersection & intersection) {
    
    // Setup basic parameters
    vec3 diff = position - intersection.getPosition();
    float dist = sqrt(dot(diff, diff));
    
    // Check if the light cast shadow
    if (castShadow) {
        
        Ray ray = Ray(intersection.getPosition(), diff);
        ray.increment(); // Must do to avoid floating point
        Intersection barrier = scene.getIntersection(ray);
        bool hasShadow = barrier.hit() && barrier.getDistanceToOrigin() < dist;
        
        // Check shadow
        if (hasShadow) {
            return 0;
        }
    }
    
    // If not cast shadow or no shadow, return the normal brightness
    return calcBrightness(dist);
}

float getToLightDirection(Intersection & intersection) {
    return normalize(position - intersection.getPosition());
}
