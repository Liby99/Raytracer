#include "util/BoundingBox.h"
#include "object/Object.h"

BoundingBox::BoundingBox() {
    initiated = false;
}

BoundingBox::BoundingBox(vec3 minCorner, vec3 maxCorner) {
    setMinCorner(minCorner);
    setMaxCorner(maxCorner);
    initiated = true;
}

BoundingBox::BoundingBox(Object * obj) {
    extend(*obj);
}

float BoundingBox::getWidth() {
    return maxCorner.x - minCorner.x;
}

float BoundingBox::getHeight() {
    return maxCorner.y - minCorner.y;
}

float BoundingBox::getLength() {
    return maxCorner.z - minCorner.z;
}

vec3 BoundingBox::getSize() {
    return vec3(getWidth(), getHeight(), getLength());
}

vec3 BoundingBox::getMinCorner() {
    return minCorner;
}

vec3 BoundingBox::getMaxCorner() {
    return maxCorner;
}

vector<vec3> BoundingBox::getBoundingVertices() {
    vector<vec3> vertices;
    vertices.push_back(vec3(minCorner.x, minCorner.y, minCorner.z));
    vertices.push_back(vec3(minCorner.x, minCorner.y, maxCorner.z));
    vertices.push_back(vec3(minCorner.x, maxCorner.y, minCorner.z));
    vertices.push_back(vec3(minCorner.x, maxCorner.y, maxCorner.z));
    vertices.push_back(vec3(maxCorner.x, minCorner.y, minCorner.z));
    vertices.push_back(vec3(maxCorner.x, minCorner.y, maxCorner.z));
    vertices.push_back(vec3(maxCorner.x, maxCorner.y, minCorner.z));
    vertices.push_back(vec3(maxCorner.x, maxCorner.y, maxCorner.z));
    return vertices;
}

void BoundingBox::setMinCorner(vec3 minCorner) {
    this->minCorner = minCorner;
}

void BoundingBox::setMaxCorner(vec3 maxCorner) {
    this->maxCorner = maxCorner;
}

void BoundingBox::extend(Object & object) {
    extend(object.getBoundingBox());
}

void BoundingBox::extend(BoundingBox box) {
    setMinCorner(initiated ? minVec(minCorner, box.minCorner) : box.minCorner);
    setMaxCorner(initiated ? maxVec(minCorner, box.maxCorner) : box.maxCorner);
    initiated = true;
}

bool BoundingBox::intersect(vec3 vec) {
    return vec.x > minCorner.x && vec.y > minCorner.y && vec.z > minCorner.z &&
           vec.x < maxCorner.x && vec.y < maxCorner.y && vec.z < maxCorner.z;
}

bool BoundingBox::intersect(Ray & ray) {
    float t = 0;
    return intersect(ray, t);
}

bool BoundingBox::intersect(Ray & ray, float & t) {
    float tmin = (minCorner.x - ray.getOrigin().x) / ray.getDirection().x;
    float tmax = (maxCorner.x - ray.getOrigin().x) / ray.getDirection().x;
    if (tmin > tmax) swap(tmin, tmax);
    float tymin = (minCorner.y - ray.getOrigin().y) / ray.getDirection().y;
    float tymax = (maxCorner.y - ray.getOrigin().y) / ray.getDirection().y;
    if (tymin > tymax) swap(tymin, tymax);
    if ((tmin > tymax) || (tymin > tmax)) return false;
    if (tymin > tmin) tmin = tymin;
    if (tymax < tmax) tmax = tymax;
    float tzmin = (minCorner.z - ray.getOrigin().z) / ray.getDirection().z;
    float tzmax = (maxCorner.z - ray.getOrigin().z) / ray.getDirection().z;
    if (tzmin > tzmax) swap(tzmin, tzmax);
    if ((tmin > tzmax) || (tzmin > tmax)) return false;
    if (tzmin > tmin) tmin = tzmin;
    if (tzmax < tmax) tmax = tzmax;
    if (tmin > 0 && tmax > 0) t = tmin;
    else if (tmin < 0 && tmax > 0) t = tmax;
    else return false;
    return true;
}

bool BoundingBox::intersect(Object & object) {
    return intersect(object.getBoundingBox());
}

bool BoundingBox::intersect(BoundingBox box) {
    vec3 nmin = maxVec(minCorner, box.minCorner);
    vec3 nmax = minVec(maxCorner, box.maxCorner);
    vec3 diagnal = nmax - nmin;
    return diagnal.x > 0 && diagnal.y > 0 && diagnal.z > 0;
}

void BoundingBox::combine(BoundingBox & box) {
    setMinCorner(minVec(minCorner, box.minCorner));
    setMaxCorner(maxVec(maxCorner, box.maxCorner));
}

BoundingBox BoundingBox::combine(BoundingBox & b1, BoundingBox & b2) {
    return BoundingBox(minVec(b1.minCorner, b2.minCorner),
                       maxVec(b1.maxCorner, b2.maxCorner));
}
