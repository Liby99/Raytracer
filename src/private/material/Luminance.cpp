#include "material/Luminance.h"

const Color Luminance::DEFAULT_COLOR = Color(1, 1, 1);

Color Luminance::getShadingColor(Scene & scene, Intersection & intersection) {
    return color;
}

Luminance::Luminance() : Material() {
    setColor(DEFAULT_COLOR);
}

Luminance::Luminance(Color color) : Material() {
    setColor(color);
}

Color Luminance::getColor() {
    return color;
}

void Luminance::setColor(Color color) {
    this->color = color;
}
