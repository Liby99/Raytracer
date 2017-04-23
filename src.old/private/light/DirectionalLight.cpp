#include "light/DirectionalLight.h"
#include "scene/Scene.h"

const vec3 DirectionalLight::DEFAULT_DIRECTION = vec3(-1, -1, -1);

DirectionalLight::DirectionalLight() : Light() {
    setDirection(DEFAULT_DIRECTION);
}

DirectionalLight::DirectionalLight(const Color color) : Light(color) {
    setDirection(DEFAULT_DIRECTION);
}

DirectionalLight::DirectionalLight(const Color color, const vec3 direction) : Light(color) {
    setDirection(direction);
}

vec3 DirectionalLight::getDirection() const {
    return direction;
}

void DirectionalLight::setDirection(const vec3 direction) {
    this->direction = normalize(direction);
}

float DirectionalLight::getBrightness(const Scene & scene, const Intersection & intersection) const {
    
    // Chcek cast shadow
    if (castShadow) {
        
        Ray ray = Ray(intersection.getPosition(), -direction);
        ray.increment(intersection.getNormal()); // Must do to avoid floating point
        Intersection barrier = Intersection(ray);
        
        // Check shadow
        if (scene.getIntersection(ray, barrier)) {
            return 0;
        }
    }
    
    // If not cast shadow or no shadow, return the normal brightness
    return intensity;
}

vec3 DirectionalLight::getToLightDirection(const Intersection & intersection) const {
    return -direction;
}
