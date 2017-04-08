#include "object/Object.h"

bool InstanceObject::updateIntersect(Ray & ray, Intersection & intersection) {
    if (object.intersect(ray, intersection)) {
        intersection.setObject(*this);
        return true;
    }
    return false;
}

InstanceObject::InstanceObject(Object & object) : Object() {
    setObject(object);
}

Object & InstanceObject::getObject() {
    return *object;
}

void InstanceObject::setObject(Object & object) {
    this->object = &object;
}
