#include "object/Plane.h"

#include <iostream>

const vec3 Plane::NORMALS[] = {
    vec3(1, 0, 0),
    vec3(-1, 0, 0),
    vec3(0, 1, 0),
    vec3(0, -1, 0),
    vec3(0, 0, 1),
    vec3(0, 0, -1)
};

const int Plane::DEFAULT_ORIENTATION = Plane::Y_POSITIVE;

bool Plane::updateIntersect(Ray & ray, Intersection & intersection) {
    
    int axis = orientation / 2;
    
    // If the direction is parallel to the plane, then return false
    if (ray.getDirection()[axis] == 0) {
        
        return false;
    }
    
    // Else
    float dist = ray.getOrigin()[axis];
    float t = dist / -ray.getDirection()[axis];
    
    if (t >= 0 && intersection.needUpdate(t)) {
        
        intersection.setHit(true);
        intersection.setT(t);
        intersection.setPosition(ray.getOrigin() + t * ray.getDirection());
        intersection.setNormal(NORMALS[orientation]);
        
        return true;
    }
    else {
        return false;
    }
}

Plane::Plane() : Object() {
    setOrientation(DEFAULT_ORIENTATION);
}

Plane::Plane(int orientation) : Object() {
    setOrientation(orientation);
}

int Plane::getOrientation() {
    return orientation;
}

void Plane::setOrientation(int orientation) {
    this->orientation = orientation;
}
