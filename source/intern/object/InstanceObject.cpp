#include "object/InstanceObject.h"

bool InstanceObject::updateIntersect(Ray & ray, Intersection & intersection) {
    if (object) return object->intersect(ray, intersection);
    else return false;
}

vector<vec3> InstanceObject::getBoundingVertices() {
    if (object) return object->getBoundingBox().getBoundingVertices();
    else return vector<vec3>();
}

InstanceObject::InstanceObject() : Object() {}

InstanceObject::InstanceObject(Object & object) : Object() {
    setObject(object);
}

Object & InstanceObject::getObject() {
    return *object;
}

void InstanceObject::setObject(Object & object) {
    this->object = &object;
}
