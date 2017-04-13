#include "object/Cube.h"

const float Cube::DEFAULT_SIZE = 1;

bool Cube::updateIntersect(const Ray & ray, Intersection & intersection) const {
    
    // Get the min and max corner
    vec3 minCorner = getMinCorner();
    vec3 maxCorner = getMaxCorner();
    
    // Calculate the intersection
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
    
    float t;
    vec3 normal;
    if (tmin > 0 && tmax > 0) t = tmin;
    else if (tmin < 0 && tmax > 0) t = tmax;
    else return false;
    
    vec3 position = ray.getPoint(t);
        
    // Calculate the normal
    if (t == tymin || t == tymax) normal = position[1] > 0 ? vec3(0, 1, 0) : vec3(0, -1, 0);
    else if (t == tzmin || t == tzmax) normal = position[2] > 0 ? vec3(0, 0, 1) : vec3(0, 0, -1);
    else normal = position[0] > 0 ? vec3(1, 0, 0) : vec3(-1, 0, 0);
    
    // Try updating the intersection
    return intersection.update(t, position, normal);
}

Cube::Cube() : Object() {
    setWidth(DEFAULT_SIZE);
    setHeight(DEFAULT_SIZE);
    setLength(DEFAULT_SIZE);
}

Cube::Cube(const float width, const float height, const float length) {
    setWidth(width);
    setHeight(height);
    setLength(length);
}

float Cube::getWidth() const {
    return width;
}

void Cube::setWidth(const float width) {
    this->width = width;
}

float Cube::getHeight() const {
    return height;
}

void Cube::setHeight(const float height) {
    this->height = height;
}

float Cube::getLength() const {
    return length;
}

void Cube::setLength(const float length) {
    this->length = length;
}

vec3 Cube::getMaxCorner() const {
    return vec3(width / 2, height / 2, length / 2);
}

vec3 Cube::getMinCorner() const {
    return -getMaxCorner();
}
