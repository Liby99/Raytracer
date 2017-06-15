#include "object/CircularCloner.h"

void CircularCloner::retransform() {
    float step = 360.0f / count;
    for (int i = 0; i < count; i++) {
        float angle = step * i;
        float rad = glm::radians(angle);
        vec3 position = vec3(cos(rad) * radius, 0, sin(rad) * radius);
        instances[i]->setTranslate(position);
    }
}

void CircularCloner::reconstruct() {
    instances.clear();
    float step = 360.0f / count;
    for (int i = 0; i < count; i++) {
        float angle = step * i;
        float rad = glm::radians(angle);
        vec3 position = vec3(cos(rad) * radius, 0, sin(rad) * radius);
        InstanceObject * instance = new InstanceObject(*object);
        instance->setTranslate(position);
        instance->rotateY(-angle);
        instances.push_back(instance);
    }
}

CircularCloner::CircularCloner(Object & object) : Cloner(object) {
    this->radius = 1;
    this->count = 5;
    reconstruct();
}

CircularCloner::CircularCloner(Object & object, float radius, int count) : Cloner(object) {
    this->radius = radius;
    this->count = count;
}

float CircularCloner::getRadius() {
    return radius;
}

void CircularCloner::setRadius(float radius) {
    this->radius = radius;
    retransform();
}

int CircularCloner::getCount() {
    return count;
}

void CircularCloner::setCount(int count) {
    this->count = count;
    reconstruct();
}
