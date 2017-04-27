#include "object/Cylinder.h"

const float Cylinder::DEFAULT_HEIGHT = 1.0f;
const float Cylinder::DEFAULT_RADIUS = 0.5f;

bool Cylinder::higher(float h) {
    return h > height / 2;
}

bool Cylinder::lower(float h) {
    return h < -height / 2;
}

bool Cylinder::inHeight(float h) {
    return !higher(h) && !lower(h);
}

bool Cylinder::updateIntersect(Ray & ray, Intersection & intersection) {
    
    // Prepare the basic parameters
    int axis = getAxis();
    float halfHeight = height / 2;
    vec3 p0 = ray.getOrigin();
    vec3 p1 = ray.getDirection();
    p0[axis] = 0;
    p1[axis] = 0;
    
    // Calculate t
    float t;
    bool hit = false;
    float a = dot(p1, p1);
    float b = 2.0f * dot(p1, p0);
    float c = dot(p0, p0) - radius * radius;
    float t1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    float t2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    
    vec3 pos;
    vec3 normal;
    
    if (t1 > 0 && t2 > 0) {
        
        if (t1 > t2) swap(t1, t2);
        
        vec3 pos1 = ray.getPoint(t1);
        vec3 pos2 = ray.getPoint(t2);
        
        // Check which surface is the ray intersecting
        if (inHeight(pos1[axis])) {
            
            // Intersecting the side
            t = t1;
            pos = pos1;
            normal = pos1;
            normal[axis] = 0;
            
            return intersection.update(t, pos, normal);
        }
        else if (higher(pos1[axis]) && !higher(pos2[axis])) {
            
            // Intersecting the top side
            float dist = ray.getOrigin()[axis] - halfHeight;
            t = dist / -ray.getDirection()[axis];
            pos = ray.getOrigin() + t * ray.getDirection();
            normal = NORMALS[axis * 2];
            
            return intersection.update(t, pos, normal);
        }
        else if (lower(pos1[axis]) && !lower(pos2[axis])) {
            
            // Intersecting the bottom side
            float dist = ray.getOrigin()[axis] - halfHeight;
            t = dist / -ray.getDirection()[axis];
            pos = ray.getOrigin() + t * ray.getDirection();
            normal = NORMALS[axis * 2 + 1];
            
            return intersection.update(t, pos, normal);
        }
        else {
            
            // No Intersection
            return false;
        }
    }
    else if (t1 * t2 < 0) {
        
        //
        t = max(t1, t2);
        pos = ray.getOrigin() + t * ray.getDirection();
        
        // check if in height
        if (inHeight(pos[axis])) {
            
            // Set normal
            normal = pos;
            normal[axis] = 0;
            
            return intersection.update(t, pos, normal);
        }
        else {
            return false;
        }
    }
    
    return false;
}

vector<vec3> Cylinder::getBoundingVertices() {
    float hh = height / 2;
    int a = getAxis();
    vector<vec3> result;
    result.push_back(vec3(radius, radius, radius));
    result.push_back(vec3(radius, radius, -radius));
    result.push_back(vec3(radius, -radius, radius));
    result.push_back(vec3(radius, -radius, -radius));
    result.push_back(vec3(-radius, radius, radius));
    result.push_back(vec3(-radius, radius, -radius));
    result.push_back(vec3(-radius, -radius, radius));
    result.push_back(vec3(-radius, -radius, -radius));
    for (int i = 0; i < result.size(); i++) {
        result[i][a] = (result[i][a] > 0) ? hh : -hh;
    }
    return result;
}

Cylinder::Cylinder() : Object(), Orientable() {
    setHeight(DEFAULT_HEIGHT);
    setRadius(DEFAULT_RADIUS);
}

Cylinder::Cylinder(float height, float radius) : Object(), Orientable() {
    setHeight(height);
    setRadius(radius);
}

Cylinder::Cylinder(int orientation) : Object(), Orientable(orientation) {
    setHeight(DEFAULT_HEIGHT);
    setRadius(DEFAULT_RADIUS);
}

Cylinder::Cylinder(int orientation, float height, float radius) : Object(), Orientable(orientation) {
    setHeight(height);
    setRadius(radius);
}

float Cylinder::getHeight() {
    return height;
}

void Cylinder::setHeight(float height) {
    this->height = height;
}

float Cylinder::getRadius() {
    return radius;
}

void Cylinder::setRadius(float radius) {
    this->radius = radius;
}
