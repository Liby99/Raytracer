#include "material/Ambient.h"

const Color Ambient::DEFAULT_AMBIENT = Color(0.1, 0.1, 0.1);

Color Ambient::getShadingColor(Scene & scene, Intersection & intersection) {
    return ambient;
}

Ambient::Ambient() : Material() {
    setAmbient(DEFAULT_AMBIENT);
}

Ambient::Ambient(Color ambient) : Material() {
    setAmbient(ambient);
}

Color Ambient::getAmbient() {
    return ambient;
}

void Ambient::setAmbient(Color ambient) {
    this->ambient = ambient;
}
