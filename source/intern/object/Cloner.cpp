#include "object/Cloner.h"

bool Cloner::updateIntersect(Ray & ray, Intersection & intersection) {
    bool result = false;
    for (int i = 0; i < instances.size(); i++) {
        if (instances[i]->intersect(ray, intersection, 0)) {
            result = true;
        }
    }
    return result;
}

vec3 Cloner::sampleSurfacePointHelper(float t) {
    return instances[rand() % instances.size()]->sampleSurfacePoint(t);
}

Cloner::Cloner(Object & object) : Object() {
    this->object = &object;
}
