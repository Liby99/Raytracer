#include "material/Diffuse.h"
#include "scene/Scene.h"

const Color Diffuse::DEFAULT_DIFFUSE = Color(1, 1, 1);

Color Diffuse::getShadingColor(const Scene & scene, const Intersection & intersection) const {
    Color color;
    #pragma omp parallel for
    for (int i = 0; i < scene.lightAmount(); i++) {
        
        // Get Light Info
        Light & light = scene.getLight(i);
        Color lc = light.getColor() * light.getBrightness(scene, intersection);
        
        // Pre cache normal and direction and calculate lambert
        vec3 normal = intersection.getNormal();
        vec3 dir = light.getToLightDirection(intersection);
        Color lambert = diffuse * max(dot(normal, dir), 0.0f);
        
        // Multiply them together
        color += lc * lambert;
    }
    return color;
}

Diffuse::Diffuse() {
    setDiffuse(DEFAULT_DIFFUSE);
}

Diffuse::Diffuse(const Color diffuse) : Material() {
    setDiffuse(diffuse);
}

Color Diffuse::getDiffuse() const {
    return diffuse;
}

void Diffuse::setDiffuse(const Color diffuse) {
    this->diffuse = diffuse;
}
