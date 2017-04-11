#include "object/Sphere.h"

bool Sphere::updateIntersect(Ray & ray, Intersection & intersection) {
    
    vec3 p0 = ray.getOrigin();
    vec3 p1 = ray.getDirection();
    
    float t;
    bool hit = false;
    float a = dot(p1, p1);
    float b = 2.0f * dot(p1, p0);
    float c = dot(p0, p0) - radius * radius;
    float t1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    float t2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

    if (t1 > 0 && t2 > 0) {
        hit = true;
        t = min(t1, t2);
    }
    else if (t1 * t2 < 0) {
        hit = true;
        t = max(t1, t2);
    }

    if (hit) {
        
        // Update the intersection
        vec3 position = ray.getPoint(t);
        
        // Return intersection update
        return intersection.update(t, position, position);
    }
    
    return false;
}

Sphere::Sphere() {
    setRadius(1);
}

Sphere::Sphere(float radius) {
    setRadius(radius);
}

float Sphere::getRadius() {
    return radius;
}

void Sphere::setRadius(float radius) {
    this->radius = radius;
}
