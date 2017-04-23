#include "object/GridCloner.h"

const float GridCloner::DEFAULT_SIZE = 2;
const unsigned int GridCloner::DEFAULT_COUNT = 3;

bool GridCloner::updateIntersect(const Ray & ray, Intersection & intersection) const {
    return Cloner::updateIntersect(ray, intersection);
}

void GridCloner::updateCache() {
    Cloner::updateCache();
    float halfWidth = width / 2;
    float halfHeight = height / 2;
    float halfLength = length / 2;
    for (int i = 0; i < xCount; i++) {
        for (int j = 0; j < yCount; j++) {
            for (int k = 0; k < zCount; k++) {
                InstanceObject ins = InstanceObject(*object);
                ins.translate(vec3(-halfWidth + width * i / xCount,
                                   -halfHeight + height * j / yCount,
                                   -halfLength + length * k / zCount));
                cache.push_back(ins);
            }
        }
    }
}

void GridCloner::updateSize() {
    float halfWidth = width / 2;
    float halfHeight = height / 2;
    float halfLength = length / 2;
    for (int i = 0; i < xCount; i++) {
        for (int j = 0; j < yCount; j++) {
            for (int k = 0; k < zCount; k++) {
                vec3 pos = vec3(-halfWidth + width * i / xCount,
                               -halfHeight + height * j / yCount,
                               -halfLength + length * k / zCount);
                cache[i].setTranslate(pos);
            }
        }
    }
}

GridCloner::GridCloner() : Cloner() {
    setWidth(DEFAULT_SIZE);
    setHeight(DEFAULT_SIZE);
    setLength(DEFAULT_SIZE);
    setXCount(DEFAULT_COUNT);
    setYCount(DEFAULT_COUNT);
    setZCount(DEFAULT_COUNT);
    updateCache();
}

GridCloner::GridCloner(const Object & object) : Cloner(object) {
    setWidth(DEFAULT_SIZE);
    setHeight(DEFAULT_SIZE);
    setLength(DEFAULT_SIZE);
    setXCount(DEFAULT_COUNT);
    setYCount(DEFAULT_COUNT);
    setZCount(DEFAULT_COUNT);
    updateCache();
}

float GridCloner::getWidth() const {
    return width;
}

float GridCloner::getHeight() const {
    return height;
}

float GridCloner::getLength() const {
    return length;
}

void GridCloner::setWidth(const float width) {
    this->width = width;
    updateSize();
}

void GridCloner::setHeight(const float height) {
    this->height = height;
    updateSize();
}

void GridCloner::setLength(const float length) {
    this->length = length;
    updateSize();
}

unsigned int GridCloner::getXCount() const {
    return xCount;
}

unsigned int GridCloner::getYCount() const {
    return yCount;
}

unsigned int GridCloner::getZCount() const {
    return zCount;
}

void GridCloner::setXCount(const unsigned int xCount) {
    this->xCount = xCount;
    updateCache();
}

void GridCloner::setYCount(const unsigned int yCount) {
    this->yCount = yCount;
    updateCache();
}

void GridCloner::setZCount(const unsigned int zCount) {
    this->zCount = zCount;
    updateCache();
}
