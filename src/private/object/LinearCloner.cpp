#include "object/LinearCloner.h"

const vec3 LinearCloner::DEFAULT_GAP = vec3(0, 1, 0);
const unsigned int LinearCloner::DEFAULT_COUNT = 3;

bool LinearCloner::updateIntersect(const Ray & ray, Intersection & intersection) const {
    return Cloner::updateIntersect(ray, intersection);
}

void LinearCloner::updateCache() {
    Cloner::updateCache();
    vec3 position = vec3();
    for (int i = 0; i < count; i++) {
        InstanceObject ins = InstanceObject(*object);
        ins.translate(position);
        cache.push_back(ins);
        position += gap;
    }
}

void LinearCloner::updateGap() {
    vec3 position = vec3();
    for (int i = 0; i < cache.size(); i++) {
        cache[i].setTranslate(position);
        position += gap;
    }
}

LinearCloner::LinearCloner() : Cloner() {
    setGap(DEFAULT_GAP);
    setCount(DEFAULT_COUNT);
}

LinearCloner::LinearCloner(const Object & object) : Cloner(object) {
    setGap(DEFAULT_GAP);
    setCount(DEFAULT_COUNT);
}

LinearCloner::LinearCloner(const Object & object, const vec3 gap, const unsigned int count) {
    setGap(gap);
    setCount(count);
}

vec3 LinearCloner::getGap() const {
    return gap;
}

void LinearCloner::setGap(const vec3 gap) {
    this->gap = gap;
    updateGap();
}

unsigned int LinearCloner::getCount() const {
    return count;
}

void LinearCloner::setCount(const unsigned int count) {
    this->count = count;
    updateCache();
}
