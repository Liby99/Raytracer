#include "object/Disc.h"

const float Disc::DEFAULT_RADIUS = 0.5f;

bool Disc::updateIntersect(const Ray & ray, Intersection & intersection) const {
    
    // If the direction is parallel to the plane, then return false
    if (ray.getDirection()[getAxis()] == 0) {
        return false;
    }
    
    // Else
    float dist = ray.getOrigin()[getAxis()];
    float t = dist / -ray.getDirection()[getAxis()];
    
    // Check
    if (t >= 0) {
        
        vec3 pos = ray.getPoint(t);
        float r = sqrt(dot(pos, pos));
        
        // Check radius
        if (r <= radius) {
            return intersection.update(t, pos, NORMALS[orientation]);
        }
    }
    else {
        return false;
    }
}

vector<vec3> Disc::getBoundingVertices() {
    int a = getAxis();
    vector<vec3> result;
    result.push_back(vec3(radius, radius, radius));
    result.push_back(vec3(radius, radius, -radius));
    result.push_back(vec3(radius, -radius, radius));
    result.push_back(vec3(radius, -radius, -radius));
    result.push_back(vec3(-radius, radius, radius));
    result.push_back(vec3(-radius, radius, -radius));
    result.push_back(vec3(-radius, -radius, radius));
    result.push_back(vec3(-radius, -radius, -radius));
    for (int i = 0; i < result.size(); i++) {
        result[i][a] = 0;
    }
    return result;
}

Disc::Disc() : Object(), Orientable() {
    setRadius(DEFAULT_RADIUS);
}

Disc::Disc(const float radius) : Object(), Orientable() {
    setRadius(radius);
}

Disc::Disc(const float radius, const int orientation) : Object(), Orientable(orientation) {
    setRadius(radius);
}

float Disc::getRadius() const {
    return radius;
}

void Disc::setRadius(const float radius) {
    this->radius = radius;
}
