#include "light/AreaLight.h"
#include "scene/Scene.h"

#include <iostream>
using namespace std;

const float AreaLight::DEFAULT_WIDTH = 1;
const float AreaLight::DEFAULT_HEIGHT = 1;

float AreaLight::calcBrightness(float dist) {
    return intensity / (fallOff.x + fallOff.y * dist + fallOff.z * dist * dist);
}

bool AreaLight::updateIntersect(Ray & ray, Intersection & intersection) {
    
    // If the direction is parallel to the plane, then return false
    int a = getAxis();
    float hw = width / 2.0f;
    float hh = height / 2.0f;
    if (ray.getDirection()[a] == 0) {
        return false;
    }
    
    // Calculate t
    float dist = ray.getOrigin()[a];
    float t = dist / -ray.getDirection()[a];
    
    // Check if the t is valid
    if (t >= 0) {
        vec3 pos = ray.getPoint(t);
        float w = pos[(a + 1) % 3];
        float h = pos[(a + 2) % 3];
        if (-hw <= w <= hw && -hh <= h <= hh) {
            return intersection.update(t, pos, NORMALS[orientation]);
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

vector<vec3> AreaLight::getBoundingVertices() {
    vector<vec3> result;
    float hw = width / 2.0f;
    float hh = height / 2.0f;
    int a = getAxis();
    for (int i = 0; i < 4; i++) {
        vec3 v;
        v[a] = 0;
        v[(a + 1) % 3] = pow(-1, i % 2) * hw;
        v[(a + 2) % 3] = pow(-1, i / 2) * hh;
        result.push_back(v);
    }
    return result;
}

AreaLight::AreaLight() : AreaLight(DEFAULT_WIDTH, DEFAULT_HEIGHT) {}

AreaLight::AreaLight(Color color, float width, float height, int orientation) : Light(), Object(), Orientable(orientation) {
    
    lum = nullptr;
    setColor(color);
    
    // Set basic
    setWidth(width);
    setHeight(height);
    
    // Set sampling
    setSamplingMethod(Sampler::UNIFORM_SAMPLE);
    setWeightingMethod(Sampler::NO_WEIGHT);
}

AreaLight::AreaLight(float width, float height) : Light(), Object(), Orientable() {
    
    lum = nullptr;
    setColor(Color::WHITE);
    
    // Set basic
    setWidth(width);
    setHeight(height);
    
    // Set sampling
    setSamplingMethod(Sampler::UNIFORM_SAMPLE);
    setWeightingMethod(Sampler::NO_WEIGHT);
}

AreaLight::~AreaLight() {
    delete lum;
}

void AreaLight::setColor(Color color) {
    Light::setColor(color);
    if (!lum) {
        lum = new Luminance(color);
    }
    else {
        lum->setColor(color);
    }
}

bool AreaLight::hasMaterial() {
    return true;
}

Material & AreaLight::getMaterial() {
    return *lum;
}

float AreaLight::getWidth() {
    return width;
}

float AreaLight::getHeight() {
    return height;
}

void AreaLight::setWidth(float width) {
    this->width = width;
}

void AreaLight::setHeight(float height) {
    this->height = height;
}

vec3 AreaLight::getFallOff() {
    return fallOff;
}

void AreaLight::setFallOff(vec3 fallOff) {
    this->fallOff = fallOff;
}

void AreaLight::setSamplingMethod(int samplingMethod) {
    this->samplingMethod = samplingMethod;
}

void AreaLight::setWeightingMethod(int weightingMethod) {
    this->weightingMethod = weightingMethod;
}

float AreaLight::getBrightness(Scene & scene, Intersection & intersection, Ray & toLight, float t) {
    
    // Setup basic parameters
    Intersection lightItsct = Intersection(toLight);
    intersect(toLight, lightItsct, t);
    vec3 diff = lightItsct.getPosition() - intersection.getPosition();
    float dist = sqrt(dot(diff, diff));
    
    // Check if the light cast shadow
    if (castShadow) {
        
        Ray ray = Ray(intersection.getPosition(), diff);
        ray.increment(intersection.getNormal()); // Must do to avoid floating point
        Intersection barrier = Intersection(ray);
        
        // Check shadow
        if (scene.getIntersection(ray, barrier, t) && barrier.getDistanceToOrigin() < dist) {
            return 0;
        }
    }
    
    // If not cast shadow or no shadow, return the normal brightness
    return calcBrightness(dist);
}

vector<vec3> AreaLight::getToLightDirection(Intersection & intersection, int sampleAmount, float t) {
    vector<vec3> result;
    vector<vec2> samples = Sampler::sample2D(sampleAmount, samplingMethod, weightingMethod);
    int a = getAxis();
    int side = sqrt(samples.size());
    float hw = width / 2.0f;
    float hh = height / 2.0f;
    float wi = (float) width / side;
    float hi = (float) height / side;
    mat4 tr = getTransformMatrix(t);
    vec3 pos = intersection.getPosition();
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            vec3 v;
            v[a] = 0;
            v[(a + 1) % 3] = -hw + wi * (i + samples[j + i * side].x);
            v[(a + 2) % 3] = -hh + hi * (j + samples[j + i * side].y);
            vec4 _v = tr * vec4(v, 1);
            v = vec3(_v) / _v.w;
            result.push_back(v - pos);
        }
    }
    return result;
}
