#include "object/Cube.h"

const float Cube::DEFAULT_SIZE = 1;

bool Cube::updateIntersect(Ray & ray, Intersection & intersection) {
    
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

vector<vec3> Cube::getBoundingVertices() {
    float hw = width / 2;
    float hh = height / 2;
    float hl = length / 2;
    vector<vec3> result;
    result.push_back(vec3(hw, hh, hl));
    result.push_back(vec3(hw, hh, -hl));
    result.push_back(vec3(hw, -hh, hl));
    result.push_back(vec3(hw, -hh, -hl));
    result.push_back(vec3(-hw, hh, hl));
    result.push_back(vec3(-hw, hh, -hl));
    result.push_back(vec3(-hw, -hh, hl));
    result.push_back(vec3(-hw, -hh, -hl));
    return result;
}

vec3 Cube::sampleSurfacePointHelper(float t) {
    
    // Initiate Random Value
    int face = rand() % 6,
        axis = face / 2, a1 = (axis + 1) % 3, a2 = (axis + 2) % 3,
        sign = face % 2;
    vec2 sample = Sampler::random2D();
    
    // Initiate Corner Vector and result point
    vec3 corner = vec3(width / 2, height / 2, length / 2), point;
    
    // Setup point
    point[axis] = pow(-1, sign) * corner[axis];
    point[a1] = -corner[a1] + 2 * corner[a1] * sample.x;
    point[a2] = -corner[a2] + 2 * corner[a2] * sample.y;
    
    // Return the sample
    return point;
}

Cube::Cube() : Object() {
    setWidth(DEFAULT_SIZE);
    setHeight(DEFAULT_SIZE);
    setLength(DEFAULT_SIZE);
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
