#include "light/Light.h"

Light::DEFAULT_COLOR = Color(1, 1, 1);
Light::DEFAULT_INTENSITY = 1;
Light::DEFAULT_CAST_SHADOW = false;

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

float getIntensity() {
    return intensity;
}

void setIntensity(float intensity) {
    this->intensity = intensity;
}

bool getCastShadow() {
    return castShadowFlag;
}

void setCastShadow(bool castShadow) {
    this->castShadow = castShadow;
}

float getBrightness(Scene & scene, Intersection & intersection) {
    return 0;
}

vec3 getToLightDirection(Intersection & intersection) {
    return vec3(0, 0, 0);
}
