#include "material/Material.h"

Material::Material() {}

vector<pair<Ray, Color>> Material::reflection(Intersection & i, int amount) {
    return vector<pair<Ray, Color>>();
}

Color Material::emission() {
    return Color();
}
