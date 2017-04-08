#include "material/Diffuse.h"
#include "scene/Scene.h"

Diffuse::Diffuse(Color diffuse) : Material() {
    setDiffuse(diffuse);
}

Color Diffuse::getDiffuse() {
    return diffuse;
}

void Diffuse::setDiffuse(Color diffuse) {
    this->diffuse = diffuse;
}

Color Diffuse::shade(Scene & scene, Intersection & intersection) {
    Color color;
    for (int i = 0; i < scene.lightAmount(); i++) {
        Light & light = scene.getLight(i);
        Color lc = light.getColor() * light.getBrightness(scene, intersection);
        Color lambert = diffuse * max(dot(intersection.getNormal(), light.getToLightDirection(intersection)), 0.0f);
        color += lc * lambert;
    }
    return color;
}
