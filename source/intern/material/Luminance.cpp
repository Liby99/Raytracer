#include "material/Luminance.h"

Luminance::Luminance() : Luminance(Color::WHITE) {}

Luminance::Luminance(Color color) : Material() {
    setColor(color);
}

Color Luminance::getColor() {
    return color;
}

void Luminance::setColor(Color color) {
    this->color = color;
}

Color Luminance::emission() {
    return color;
}
