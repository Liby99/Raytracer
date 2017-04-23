#include "util/Intersection.h"
#include "object/Object.h"

Intersection::Intersection(const Ray & ray) {
    setRay(ray);
    setHit(false);
}

const Object & Intersection::getObject() const {
    return *object;
}

void Intersection::setObject(const Object & object) {
    this->object = &object;
}

const Ray & Intersection::getRay() const {
    return *ray;
}

void Intersection::setRay(const Ray & ray) {
    this->ray = &ray;
}

bool Intersection::hit() const {
    return hitFlag;
}

void Intersection::setHit(bool hit) {
    this->hitFlag = hit;
}

float Intersection::getT() const {
    return t;
}

void Intersection::setT(float t) {
    this->t = t;
}

vec3 Intersection::getPosition() const {
    return position;
}

void Intersection::setPosition(vec3 position) {
    this->position = position;
}

vec3 Intersection::getNormal() const {
    return normal;
}

void Intersection::setNormal(vec3 normal) {
    this->normal = normalize(normal);
}

float Intersection::getDistanceToOrigin() const {
    vec3 diff = position - ray->getOrigin();
    return sqrt(dot(diff, diff));
}

bool Intersection::needUpdate(float t) const {
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
