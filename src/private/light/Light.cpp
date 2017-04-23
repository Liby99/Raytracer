#include "light/Light.h"

Color Light::DEFAULT_COLOR = Color(1, 1, 1);
float Light::DEFAULT_INTENSITY = 1;
bool Light::DEFAULT_CAST_SHADOW = false;

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

void Light::setColor(Color color) {
    this->color = color;
}

float Light::getIntensity() {
    return intensity;
}

void Light::setIntensity(float intensity) {
    this->intensity = intensity;
}

bool Light::getCastShadow() {
    return castShadow;
}

void Light::setCastShadow(bool castShadow) {
    this->castShadow = castShadow;
}

float Light::getBrightness(Scene & scene, Intersection & intersection) {
    return 0;
}

vec3 Light::getToLightDirection(Intersection & intersection) {
    return vec3(0, 0, 0);
}
