#include "light/AreaLight.h"
#include "scene/Scene.h"

void AreaLight::initiateLuminance() {
    initiateLuminance(Color::WHITE);
}

void AreaLight::initiateLuminance(Color color) {
    if (!lum) {
        lum = new Luminance(color, 1);
    }
}

AreaLight::AreaLight() : Light(), InstanceObject() {
    initiateLuminance();
}

AreaLight::AreaLight(Object & object) : Light(), InstanceObject(object) {
    initiateLuminance();
}

AreaLight::AreaLight(Object & object, Color color) : Light(), InstanceObject(object) {
    initiateLuminance(color);
}

Color AreaLight::getColor() {
    return lum->emission();
}

void AreaLight::setColor(Color color) {
    lum->setColor(color);
}

float AreaLight::getIntensity() {
    return lum->getIntensity();
}

void AreaLight::setIntensity(float intensity) {
    lum->setIntensity(intensity);
}

float AreaLight::getBrightness(Scene & scene, Intersection & intersection, float t) {
    Ray toLight = Ray(intersection.getPosition(), getToLightDirection(intersection));
    toLight.increment(intersection.getNormal());
    return getBrightness(scene, intersection, toLight, t);
}

float AreaLight::getBrightness(Scene & scene, Intersection & intersection, Ray & ray, float t) {
    
    Intersection lgtits = Intersection(ray);
    if (intersect(ray, lgtits, t)) {
        
        vec3 pos = lgtits.getPosition();
        vec3 origin = intersection.getPosition();
        vec3 diff = pos - origin;
        float dist = sqrt(dot(diff, diff));
        
        if (castShadow) {
            
            Intersection barrier = Intersection(ray);
            if (scene.getIntersection(ray, barrier, t) && barrier.getDistanceToOrigin() < dist) {
                return 0;
            }
        }
        
        return 1 / dist * dist;
    }
    else {
        return 0;
    }
}

vec3 AreaLight::getToLightDirection(Intersection & intersection) {
    vec3 sample = sampleSurfacePoint(0);
    vec3 pos = intersection.getPosition();
    return sample - pos;
}
