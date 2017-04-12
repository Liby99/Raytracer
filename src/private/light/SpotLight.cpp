#include "light/SpotLight.h"
#include "scene/Scene.h"

const vec3 SpotLight::DEFAULT_TARGET = vec3(0, 0, 0);
const float SpotLight::DEFAULT_ANGLE = 90;

SpotLight::SpotLight() : PointLight() {
    setTarget(DEFAULT_TARGET);
    setAngle(DEFAULT_ANGLE);
}

SpotLight::SpotLight(const Color color, const vec3 position, const vec3 target, const float angle) : PointLight(color, position) {
    setTarget(target);
    setAngle(angle);
}

vec3 SpotLight::getTarget() const {
    return target;
}

void SpotLight::setTarget(const vec3 target) {
    this->target = target;
}

float SpotLight::getAngle() const {
    return angle;
}

void SpotLight::setAngle(const float angle) {
    this->angle = angle;
}

float SpotLight::getBrightness(const Scene & scene, const Intersection & intersection) const {
    
    vec3 itsDir = normalize(intersection.getPosition() - position);
    vec3 lgtDir = normalize(target - position);
    float deg = glm::degrees(glm::acos(dot(itsDir, lgtDir)));
    
    if (deg > 0 && deg < angle / 2) {
        return PointLight::getBrightness(scene, intersection);
    }
    else {
        return 0;
    }
}

vec3 SpotLight::getToLightDirection(const Intersection & intersection) const {
    return normalize(position - intersection.getPosition());
}
