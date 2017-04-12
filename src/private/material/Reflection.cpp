#include "material/Reflection.h"
#include "scene/Scene.h"

const Color Reflection::DEFAULT_TINT = Color(1, 1, 1);
const float Reflection::DEFAULT_ATTENUATION = 0.8;

Color Reflection::getShadingColor(const Scene & scene, const Intersection & intersection) const {
    
    if (intersection.getRay().canRecurse()) {
        
        // First calculate the reflection ray
        int depth = intersection.getRay().getDepth();
        vec3 origin = intersection.getPosition();
        vec3 normal = intersection.getNormal();
        vec3 rayDir = intersection.getRay().getDirection();
        vec3 direction = rayDir - vec3(2 * dot(rayDir, normal)) * normal;
        
        // Construct reflection ray
        Ray reflect = Ray(origin, direction, depth + 1);
        reflect.increment(normal);
        
        // Then construct and return the color
        return tint * scene.getRayColor(reflect) * attenuation;
    }
    else {
        return Color();
    }
}

Reflection::Reflection() {
    setTint(DEFAULT_TINT);
    setAttenuation(DEFAULT_ATTENUATION);
}

Reflection::Reflection(const Color tint) {
    setTint(tint);
    setAttenuation(DEFAULT_ATTENUATION);
}

Color Reflection::getTint() const {
    return tint;
}

void Reflection::setTint(const Color tint) {
    this->tint = tint;
}

float Reflection::getAttenuation() const {
    return attenuation;
}

void Reflection::setAttenuation(const float attenuation) {
    this->attenuation = attenuation;
}
