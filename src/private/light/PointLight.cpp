#include "light/PointLight.h"

PointLight::DEFAULT_FALL_OFF = vec3(0, 0, 1);
PointLight::DEFAULT_POSITION = vec3(0, 0, 0);

PointLight::PointLight(Color color) {
    setColor(color);
    setPosition(DEFAULT_POSITION);
    setFallOff(DEFAULT_FALL_OFF);
}

PointLight::PointLight(Color color, vec3 position) {
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

float getBrightness(Intersection & intersection) {
    vec3 diff = position - intersection.position;
    float dist = sqrt(dot(diff, diff));
    return intensity / (fallOff.x + fallOff.y * dist + fallOff.z * dist * dist);
}

float getToLightDirection(Intersection & intersection) {
    return normalize(position - intersection.position);
}
