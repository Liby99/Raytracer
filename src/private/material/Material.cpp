#include "material/Material.h"

Material::DEFAULT_OPACITY = 1;

Material::Material() {
    setOpacity(DEFAULT_OPACITY);
}

void Material::setOpacity(float opacity) {
    this->opacity = opacity;
}

float Material::getOpacity() {
    return opacity;
}

Color shade(Scene & scene, Intersection & intersection) {
    return Color();
}
