#include "material/Luminance.h"

const Color Luminance::DEFAULT_COLOR = Color(1, 1, 1);

Color Luminance::getShadingColor(const Scene & scene, const Intersection & intersection) const {
    return color;
}

Luminance::Luminance() : Material() {
    setColor(DEFAULT_COLOR);
}

Luminance::Luminance(const Color color) : Material() {
    setColor(color);
}

Color Luminance::getColor() const {
    return color;
}

void Luminance::setColor(const Color color) {
    this->color = color;
}
