#include "light/SpotLight.h"
#include "scene/Scene.h"

const vec3 SpotLight::DEFAULT_TARGET = vec3(0, 0, 0);
const float SpotLight::DEFAULT_ANGLE = 90;

SpotLight::SpotLight() : PointLight() {
    setTarget(DEFAULT_TARGET);
    setAngle(DEFAULT_ANGLE);
}

SpotLight::SpotLight(Color color, vec3 position, vec3 target, float angle) : PointLight(color, position) {
    setTarget(target);
    setAngle(angle);
}

vec3 SpotLight::getTarget() {
    return target;
}

void SpotLight::setTarget(vec3 target) {
    this->target = target;
}

float SpotLight::getAngle() {
    return angle;
}

void SpotLight::setAngle(float angle) {
    this->angle = angle;
}

float SpotLight::getBrightness(Scene & scene, Intersection & intersection) {
    
    vec3 itsDir = normalize(intersection.getPosition() - position);
    vec3 lgtDir = normalize(target - position);
    float deg = glm::degrees(glm::acos(dot(itsDir, lgtDir)));
    
    if (deg < angle / 2 && deg > 0) {
        return PointLight::getBrightness(scene, intersection);
    }
    else {
        return 0;
    }
}

vec3 SpotLight::getToLightDirection(Intersection & intersection) {
    return normalize(position - intersection.getPosition());
}