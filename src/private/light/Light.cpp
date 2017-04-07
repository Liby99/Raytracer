#include "light/Light.h"

Light::DEFAULT_COLOR = Color(1, 1, 1);
Light::DEFAULT_INTENSITY = 1;

Light::Light() {
    setColor(DEFAULT_COLOR);
}

Light::Light(Color c) {
    setColor(c);
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

float getBrightness(Intersection & intersection) {
    return 0;
}

vec3 getToLightDirection(Intersection & intersection) {
    return vec3(0, 0, 0);
}
