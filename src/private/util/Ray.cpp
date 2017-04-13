#include "util/Ray.h"
#include "scene/Scene.h"

const float Ray::INCREMENT = 0.001;

int Ray::maxDepth = 3;

Ray::Ray() {
    setDepth(0);
    setInside(false);
}

Ray::Ray(vec3 origin, vec3 direction) {
    setOrigin(origin);
    setDirection(direction);
    setDepth(0);
    setInside(false);
}

Ray::Ray(vec3 origin, vec3 direction, int depth) {
    setOrigin(origin);
    setDirection(direction);
    setDepth(depth);
    setInside(false);
}

Ray::Ray(vec3 origin, vec3 direction, int depth, bool inside) {
    setOrigin(origin);
    setDirection(direction);
    setDepth(depth);
    setInside(inside);
}

vec3 Ray::getOrigin() const {
    return origin;
}

void Ray::setOrigin(vec3 origin) {
    this->origin = origin;
}

vec3 Ray::getDirection() const {
    return direction;
}

void Ray::setDirection(vec3 direction) {
    this->direction = normalize(direction);
}

int Ray::getDepth() const {
    return depth;
}

void Ray::setDepth(int depth) {
    this->depth = depth;
}

bool Ray::isInside() const {
    return inside;
}

void Ray::setInside(bool inside) {
    this->inside = inside;
}

void Ray::increment() {
    increment(direction);
}

void Ray::increment(vec3 direction) {
    origin += INCREMENT * direction;
}

vec3 Ray::getPoint(float t) const {
    return origin + t * direction;
}

bool Ray::canRecurse() const {
    return depth < maxDepth;
}

Ray Ray::transform(mat4 transf) const {
    vec4 o = transf * vec4(origin, 1);
    vec3 no = vec3(o) / o.w;
    vec3 nd = vec3(transf * vec4(direction, 0));
    return Ray(no, nd);
}

Ray Ray::inverseTransform(mat4 transf) const {
    return transform(inverse(transf));
}

int Ray::getMaxDepth() {
    return Ray::maxDepth;
}

void Ray::setMaxDepth(int maxDepth) {
    Ray::maxDepth = maxDepth;
}
