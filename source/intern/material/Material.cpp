#include "material/Material.h"

Material::Material() {}

Color Material::computeReflection(Intersection & i, Ray & out) {
    return Color();
}

vector<pair<Ray, Color>> Material::reflection(Intersection & i, int amount) {
    return vector<pair<Ray, Color>>();
}

Color Material::emission() {
    return Color::BLACK;
}
