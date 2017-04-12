#include "object/Disc.h"

const float Disc::DEFAULT_RADIUS = 0.5f;

bool Disc::updateIntersect(Ray & ray, Intersection & intersection) {
    
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

Disc::Disc() : Object(), Orientable() {
    setRadius(DEFAULT_RADIUS);
}

Disc::Disc(float radius) : Object(), Orientable() {
    setRadius(radius);
}

Disc::Disc(float radius, int orientation) : Object(), Orientable(orientation) {
    setRadius(radius);
}

float Disc::getRadius() {
    return radius;
}

void Disc::setRadius(float radius) {
    this->radius = radius;
}
