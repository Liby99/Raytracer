#include "material/Luminance.h"

Luminance::Luminance() : Luminance(Color::WHITE) {};

Luminance::Luminance(Color color) {
    setColor(color);
}

void Luminance::setColor(Color color) {
    this->color = color;
}

Color Luminance::getColor() {
    return color;
}

Color Luminance::computeReflection(Intersection & i, Ray & out) {
    return Color::BLACK;
}

vector<pair<Ray, Color>> Luminance::reflection(Intersection & i, int amount) {
    return vector<pair<Ray, Color>>();
}

Color Luminance::emission() {
    return color;
}
