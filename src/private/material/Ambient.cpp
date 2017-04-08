#include "material/Ambient.h"

Ambient::Ambient(Color ambient) : Material() {
    setAmbient(ambient);
}

Color Ambient::getAmbient() {
    return ambient;
}

void Ambient::setAmbient(Color ambient) {
    this->ambient = ambient;
}

Color Ambient::shade(Scene & scene, Intersection & intersection) {
    return ambient * opacity;
}
