#include "object/Plane.h"

bool Plane::updateIntersect(const Ray & ray, Intersection & intersection) const {
    
    // If the direction is parallel to the plane, then return false
    if (ray.getDirection()[getAxis()] == 0) {
        return false;
    }
    
    // Else
    float dist = ray.getOrigin()[getAxis()];
    float t = dist / -ray.getDirection()[getAxis()];
    
    if (t >= 0) {
        return intersection.update(t, ray.getPoint(t), NORMALS[orientation]);
    }
    else {
        return false;
    }
}

Plane::Plane() : Object(), Orientable() {
    setBoundable(false);
}

Plane::Plane(int orientation) : Object(), Orientable(orientation) {
    Plane();
}
