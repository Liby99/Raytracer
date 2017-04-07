#include "light/DirectionalLight.h"

DirectionalLight::DEFAULT_DIRECTION = vec3(-1, -1, -1);

DirectionalLight::DirectionalLight() : Light() {
    setDirection(DEFAULT_DIRECTION);
}

DirectionalLight::DirectionalLight(Color color) : Light(color) {
    setDirection(DEFAULT_DIRECTION);
}

DirectionalLight::DirectionalLight(Color color, vec3 direction) : Light(color) {
    setDirection(direction);
}

vec3 DirectionalLight::getDirection() {
    return direction;
}

void DirectionalLight::setDirection(vec3 direction) {
    this->direction = normalize(direction);
}

float getBrightness(Scene & scene, Intersection & intersection) {
    
    // Chcek cast shadow
    if (castShadow) {
        
        Ray ray = Ray(intersection.getPosition(), -direction);
        ray.increment(); // Must do to avoid floating point
        Intersection barrier = scene.getIntersection(ray);
        
        // Check shadow
        if (barrier.hit()) {
            return 0;
        }
    }
    
    // If not cast shadow or no shadow, return the normal brightness
    return intensity;
}

vec3 getToLightDirection(Intersection & intersection) {
    return -direction;
}
