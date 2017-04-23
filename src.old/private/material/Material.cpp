#include "material/Material.h"

const float Material::DEFAULT_OPACITY = 1;

Color Material::getShadingColor(const Scene & scene, const Intersection & intersection) const {
    return Color();
}

Material::Material() {
    setOpacity(DEFAULT_OPACITY);
}

void Material::setOpacity(float opacity) {
    this->opacity = opacity;
}

float Material::getOpacity() const {
    return opacity;
}

Color Material::shade(const Scene & scene, const Intersection & intersection) const {
    return getShadingColor(scene, intersection) * opacity;
}
