#include "util/Ray.h"
#include "scene/Scene.h"

const float Ray::INCREMENT = 0.0001;

int Ray::maxDepth = 5;

Ray::Ray() {
    
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

vec3 Ray::getOrigin() {
    return origin;
}

void Ray::setOrigin(vec3 origin) {
    this->origin = origin;
}

vec3 Ray::getDirection() {
    return direction;
}

void Ray::setDirection(vec3 direction) {
    this->direction = normalize(direction);
}

int Ray::getDepth() {
    return depth;
}

void Ray::setDepth(int depth) {
    this->depth = depth;
}

bool Ray::isInside() {
    return inside;
}

void Ray::setInside(bool inside) {
    this->inside = inside;
}

void Ray::increment() {
    origin += INCREMENT * direction;
}

Ray Ray::transform(mat4 transf) {
    vec4 o = transf * vec4(origin, 1);
    vec3 no = vec3(o) / o.w;
    vec3 nd = vec3(transf * vec4(direction, 0));
    return Ray(no, nd);
}

Ray Ray::inverseTransform(mat4 transf) {
    return transform(inverse(transf));
}

int Ray::getMaxDepth() {
    return Ray::maxDepth;
}

void Ray::setMaxDepth(int maxDepth) {
    Ray::maxDepth = maxDepth;
}
