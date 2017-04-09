#include "material/Specular.h"
#include "scene/Scene.h"

const float Specular::DEFAULT_SHININESS = 20;

Specular::Specular(Color specular) : Material() {
    setSpecular(specular);
    setShininess(DEFAULT_SHININESS);
}

Specular::Specular(Color specular, float shininess) : Material() {
    setSpecular(specular);
    setShininess(shininess);
}

Color Specular::getSpecular() {
    return specular;
}

void Specular::setSpecular(Color specular) {
    this->specular = specular;
}

float Specular::getShininess() {
    return shininess;
}

void Specular::setShininess(float shininess) {
    this->shininess = shininess;
}

Color Specular::shade(Scene & scene, Intersection & intersection) {
    Color color;
    for (int i = 0; i < scene.lightAmount(); i++) {
        
        // Store the temporary light
        Light & light = scene.getLight(i);
        
        // Get the brightness
        float brightness = light.getBrightness(scene, intersection);
        if (brightness == 0) {
            continue;
        }
        
        // Then calculate the color
        Color lc = light.getColor() * brightness;
        vec3 halfAngle = normalize(light.getToLightDirection(intersection) - intersection.getRay().getDirection());
        Color blinn = specular * pow(max(dot(intersection.getNormal(), halfAngle), 0.0f), shininess);
        color += lc * blinn;
    }
    return color * opacity;
}
