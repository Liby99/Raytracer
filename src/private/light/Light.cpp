#include "light/Light.h"

const Color Light::DEFAULT_COLOR = Color(1, 1, 1);
const float Light::DEFAULT_INTENSITY = 1;
const bool Light::DEFAULT_CAST_SHADOW = false;

Light::Light() {
    setColor(DEFAULT_COLOR);
    setIntensity(DEFAULT_INTENSITY);
    setCastShadow(DEFAULT_CAST_SHADOW);
}

Light::Light(Color c) {
    setColor(c);
    setIntensity(DEFAULT_INTENSITY);
    setCastShadow(DEFAULT_CAST_SHADOW);
}

Color Light::getColor() {
    return color;
}

void Light::setColor(const Color color) {
    this->color = color;
}

float Light::getIntensity() const {
    return intensity;
}

void Light::setIntensity(const float intensity) {
    this->intensity = intensity;
}

bool Light::getCastShadow() const {
    return castShadow;
}

void Light::setCastShadow(const bool castShadow) {
    this->castShadow = castShadow;
}

float Light::getBrightness(const Scene & scene, const Intersection & intersection) const {
    return 0;
}

vec3 Light::getToLightDirection(const Intersection & intersection) const {
    return vec3(0, 0, 0);
}
