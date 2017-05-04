#include "util/Intersection.h"
#include "object/Object.h"

Intersection::Intersection(Ray & ray) {
    setRay(ray);
    setHit(false);
}

Object & Intersection::getObject() {
    return *object;
}

void Intersection::setObject(Object & object) {
    this->object = &object;
}

Ray & Intersection::getRay() {
    return *ray;
}

void Intersection::setRay(Ray & ray) {
    this->ray = &ray;
}

bool Intersection::hit() {
    return hitFlag;
}

void Intersection::setHit(bool hit) {
    this->hitFlag = hit;
}

float Intersection::getT() {
    return t;
}

void Intersection::setT(float t) {
    this->t = t;
}

vec3 Intersection::getPosition() {
    return position;
}

void Intersection::setPosition(vec3 position) {
    this->position = position;
}

vec3 Intersection::getNormal() {
    return normal;
}

void Intersection::setNormal(vec3 normal) {
    this->normal = normalize(normal);
}

float Intersection::getDistanceToOrigin() {
    vec3 diff = position - ray->getOrigin();
    return sqrt(dot(diff, diff));
}

bool Intersection::needUpdate(float t) {
    return !hit() || t < getT();
}

bool Intersection::update(float t, vec3 position, vec3 normal) {
    if (needUpdate(t)) {
        setHit(true);
        setT(t);
        setPosition(position);
        setNormal(normal);
        return true;
    }
    else {
        return false;
    }
}

void Intersection::transform(mat4 transform) {
    vec4 nPos = transform * vec4(position, 1);
    vec4 nNorm = transpose(inverse(transform)) * vec4(normal, 0);
    setPosition(vec3(nPos) / nPos.w);
    setNormal(vec3(nNorm));
}