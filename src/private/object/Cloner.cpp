#include "object/Cloner.h"

bool Cloner::updateIntersect(const Ray & ray, Intersection & intersection) const {
    if (object) {
        bool result;
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].intersect(ray, intersection)) {
                result = true;
            }
        }
        if (result) {
            intersection.setObject(*this);
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
    updateCache();
}

Cloner::Cloner(const Object & object) : InstanceObject(object) {
    updateCache();
}
