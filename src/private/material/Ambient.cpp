#include "material/Ambient.h"

Ambient::Ambient(Color ambient) : Material() {
    setAmbient(ambient);
}

Color getAmbient() {
    return ambient;
}

void setAmbient(Color ambient) {
    this->ambient = ambient;
}

Color shade(Scene & scene, Intersection & intersection) {
    return ambient * opacity;
}
