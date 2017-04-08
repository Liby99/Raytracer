#include "object/Cube.h"

Cube::Cube() {
    setWidth(1);
    setHeight(1);
    setLength(1);
}

Cube::Cube(float width, float height, float length) {
    setWidth(width);
    setHeight(height);
    setLength(length);
}

float Cube::getWidth() {
    return width;
}

void Cube::setWidth(float width) {
    this->width = width;
}

float Cube::getHeight() {
    return height;
}

void Cube::setHeight(float height) {
    this->height = height;
}

float Cube::getLength() {
    return length;
}

void Cube::setLength(float length) {
    this->length = length;
}

vec3 Cube::getMaxCorner() {
    return vec3(width / 2, height / 2, length / 2);
}

vec3 Cube::getMinCorner() {
    return -getMaxCorner();
}

bool Cube::intersect(Ray & ray, Intersection & intersection) {
    
    Ray transfRay = ray.inverseTransform(getTransformMatrix());
    
    // Get the min and max corner
    vec3 minCorner = getMinCorner();
    vec3 maxCorner = getMaxCorner();
    
    // Calculate the intersection
    float tmin = (minCorner.x - transfRay.getOrigin().x) / transfRay.getDirection().x;
    float tmax = (maxCorner.x - transfRay.getOrigin().x) / transfRay.getDirection().x;
    if (tmin > tmax) swap(tmin, tmax);
    float tymin = (minCorner.y - transfRay.getOrigin().y) / transfRay.getDirection().y;
    float tymax = (maxCorner.y - transfRay.getOrigin().y) / transfRay.getDirection().y;
    if (tymin > tymax) swap(tymin, tymax);
    if ((tmin > tymax) || (tymin > tmax)) return false;
    if (tymin > tmin) tmin = tymin;
    if (tymax < tmax) tmax = tymax;
    float tzmin = (minCorner.z - transfRay.getOrigin().z) / transfRay.getDirection().z;
    float tzmax = (maxCorner.z - transfRay.getOrigin().z) / transfRay.getDirection().z;
    if (tzmin > tzmax) swap(tzmin, tzmax);
    if ((tmin > tzmax) || (tzmin > tmax)) return false;
    if (tzmin > tmin) tmin = tzmin;
    if (tzmax < tmax) tmax = tzmax;
    
    float t;
    if (tmin > 0 && tmax > 0) {
        t = tmin;
    }
    else if (tmin < 0 && tmax > 0) {
        t = tmax;
    }
    else {
        return false;
    }
    
    if (!intersection.hit() || t < intersection.getT()) {
        
        vec3 normals [] = { vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1) };
        
        // Calculate the normal
        vec3 position = ray.getOrigin() + t * ray.getDirection();
        float xy = position.y / position.x;
        float zy = position.y / position.z;
        int index = (xy >= -1 && xy <= 1) ? 1 : (zy >= -1 && zy <= 1) ? 2 : 0;
        float sign = position[index] > 0 ? 1.0f : -1.0f;
        vec3 normal = normals[index] * sign;
        
        intersection.setObject(*this);
        intersection.setHit(true);
        intersection.setT(t);
        intersection.setPosition(position);
        intersection.setNormal(normal);
        intersection.transform(getTransformMatrix());
    }
    
    return true;
}
