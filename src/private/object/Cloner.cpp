#include "object/Cloner.h"

bool Cloner::updateIntersect(Ray & ray, Intersection & intersection) {
    if (object) {
        bool result;
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].intersect(ray, intersection)) {
                result = true;
            }
        }
        return result;
    }
    else {
        return false;
    }
}

void Cloner::updateCache() {
    cache = vector<InstanceObject>();
}

Cloner::Cloner() : InstanceObject() {
    
}

Cloner::Cloner(Object & object) : InstanceObject(object) {
    
}
