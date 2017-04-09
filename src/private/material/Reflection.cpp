#include "material/Reflection.h"
#include "scene/Scene.h"

const float Reflection::DEFAULT_ATTENUATION = 0.8;

Reflection::Reflection() {
    setTint(Color(1, 1, 1));
    setAttenuation(DEFAULT_ATTENUATION);
}

Reflection::Reflection(Color tint) {
    setTint(tint);
    setAttenuation(DEFAULT_ATTENUATION);
}

Color Reflection::getTint() {
    return tint;
}

void Reflection::setTint(Color tint) {
    this->tint = tint;
}

float Reflection::getAttenuation() {
    return attenuation;
}

void Reflection::setAttenuation(float attenuation) {
    this->attenuation = attenuation;
}

Color Reflection::shade(Scene & scene, Intersection & intersection) {
    
    if (intersection.getRay().canRecurse()) {
        
        // First calculate the reflection ray
        int depth = intersection.getRay().getDepth();
        vec3 origin = intersection.getPosition();
        vec3 normal = intersection.getNormal();
        vec3 rayDir = intersection.getRay().getDirection();
        vec3 direction = rayDir - vec3(2.0 * dot(rayDir, normal)) * normal;
        
        // Construct reflection ray
        Ray reflect = Ray(origin, direction, depth + 1);
        reflect.increment();
        
        // Then construct and return the color
        return tint * scene.getRayColor(reflect) * attenuation * opacity;
    }
    else {
        return Color();
    }
}
