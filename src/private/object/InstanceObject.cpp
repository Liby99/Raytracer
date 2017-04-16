#include "object/InstanceObject.h"

bool InstanceObject::updateIntersect(const Ray & ray, Intersection & intersection) const {
    return object->intersect(ray, intersection);
}

vector<vec3> InstanceObject::getBoundingVertices() {
    return object->getBoundingVertices();
}

InstanceObject::InstanceObject() : Object() {
    
}

InstanceObject::InstanceObject(const Object & object) : Object() {
    setObject(object);
}

const Object & InstanceObject::getObject() const {
    return *object;
}

void InstanceObject::setObject(const Object & object) {
    this->object = &object;
}
