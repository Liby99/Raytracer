#include "object/LinearCloner.h"

bool LinearCloner::updateIntersect(Ray & ray, Intersection & intersection) {
    return Cloner::updateIntersect(ray, intersection);
}

void LinearCloner::updateCache() {
    Cloner::updateCache();
    vec3 position = vec3();
    for (int i = 0; i < count; i++) {
        InstanceObject ins = InstanceObject(object);
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

LinearCloner::LinearCloner(Object & object) : Cloner(object) {
    setGap(DEFAULT_GAP);
    setCount(DEFAULT_COUNT);
}

LinearCloner::LinearCloner(Object & object, vec3 gap, unsigned int count) {
    setGap(gap);
    setCount(count);
}

vec3 getGap() {
    return gap;
}

void setGap(vec3 gap) {
    this->gap = gap;
    updateGap();
}

unsigned int getCount() {
    return count;
}

void setCount(unsigned int count) {
    this->count = count;
    updateCache();
}
