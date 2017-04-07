#include "light/Light.h"

Light::DEFAULT_COLOR = Color(1, 1, 1);
Light::DEFAULT_FALL_OFF = vec3(0, 0, 1);

Light::Light() {
    setColor(DEFAULT_COLOR);
    setFallOff(DEFAULT_FALL_OFF);
}

Light::Light(Color c) {
    setColor(c);
    setFallOff(DEFAULT_FALL_OFF);
}

Light::Light(Color c, vec3 fallOff) {
    setColor(c);
    setFallOff(fallOff);
}

Color Light::getColor() {
    return color;
}

void Light::setColor(Color color) {
    this.color = color;
}

vec3 getFallOff() {
    return fallOff;
}

void setFallOff(vec3 fallOff) {
    this.fallOff = fallOff;
}

float illuminate(Intersection & intersection) {
    return 0;
}
