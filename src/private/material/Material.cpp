#include "material/Material.h"

const float Material::DEFAULT_OPACITY = 1;

Color Material::getShadingColor(Scene & scene, Intersection & intersection) {
    return Color();
}

Material::Material() {
    setOpacity(DEFAULT_OPACITY);
}

void Material::setOpacity(float opacity) {
    this->opacity = opacity;
}

float Material::getOpacity() {
    return opacity;
}

Color Material::shade(Scene & scene, Intersection & intersection) {
    return getShadingColor(scene, intersection) * opacity;
}
