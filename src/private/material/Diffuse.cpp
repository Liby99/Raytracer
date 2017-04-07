#include "material/Diffuse.h"

Diffuse:Diffuse(Color diffuse) : Material() {
    setDiffuse(diffuse);
}

Color Diffuse::getDiffuse() {
    return diffuse;
}

void Diffuse::setDiffuse(Color diffuse) {
    this->diffuse = diffuse;
}

Color shade(Scene & scene, Intersection & intersection) {
    Color color;
    for (int i = 0; i < scene.lightAmount(); i++) {
        Light & light = scene.getLight(i);
        Color lc = light.getColor() * light.getBrightness(scene, intersection);
        Color lambert = diffuse * max(dot(normal, light.getToLightDirection()), 0.0);
        color += lc * lambert;
    }
    return color;
}
