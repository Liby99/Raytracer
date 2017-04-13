#include "material/Ambient.h"

const Color Ambient::DEFAULT_AMBIENT = Color(0.1, 0.1, 0.1);

Color Ambient::getShadingColor(const Scene & scene, const Intersection & intersection) const {
    return ambient;
}

Ambient::Ambient() : Material() {
    setAmbient(DEFAULT_AMBIENT);
}

Ambient::Ambient(const Color ambient) : Material() {
    setAmbient(ambient);
}

Color Ambient::getAmbient() const {
    return ambient;
}

void Ambient::setAmbient(const Color ambient) {
    this->ambient = ambient;
}
