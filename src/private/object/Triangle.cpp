#include "object/Triangle.h"

#include <iostream>

vec3 Triangle::getBaryCentric(vec3 position) {
    vec3 result = vec3(0, 0, 0);
    vec3 p1 = v1->getPosition();
    vec3 p2 = v2->getPosition();
    vec3 p3 = v3->getPosition();
    vec3 t0 = p2 - p1, t1 = p3 - p1, t2 = position - p1;
    float d00 = dot(t0, t0);
    float d01 = dot(t0, t1);
    float d11 = dot(t1, t1);
    float d20 = dot(t2, t0);
    float d21 = dot(t2, t1);
    float denom = d00 * d11 - d01 * d01;
    result.x = (d11 * d20 - d01 * d21) / denom;
    result.y = (d00 * d21 - d01 * d20) / denom;
    result.z = 1.0f - result.x - result.y;
    return result;
}

bool Triangle::updateIntersect(Ray & ray, Intersection & intersection) {
    
    // Pre cache the positions
    vec3 p1 = v1->getPosition();
    vec3 p2 = v2->getPosition();
    vec3 p3 = v3->getPosition();
    
    // Same the variables
    vec3 normal = cross(p2 - p1, p3 - p1);
    
    // If three points are in a straight line, then intersection not exist
    if (normal.x == 0 && normal.y == 0 && normal.z == 0) {
        return false;
    }
    normal = normalize(normal);
    
    // Calculate t
    float t = (dot(p1, normal) - dot(ray.getOrigin(), normal)) / dot(ray.getDirection(), normal);
    
    // Pre cache the position of the intersection
    vec3 position = ray.getOrigin() + t * ray.getDirection();
    vec3 lambda = getBaryCentric(position);
    
    // Check if t is greater then 0 and the position is inside the triangle
    if (t > 0 &&
        lambda.x >= 0 && lambda.x <= 1 &&
        lambda.y >= 0 && lambda.y <= 1 &&
        lambda.z >= 0 && lambda.z <= 1) {
        
        // If the passed in intersection has not hit yet or it's further
        if (!intersection.hit() || t < intersection.getT()) {
            
            // Then update the input intersection
            intersection.setHit(true);
            intersection.setT(t);
            intersection.setPosition(position);
            intersection.setNormal(normal);
        }
        
        // Since intersect, return true
        return true;
    }
    
    // Not intersected
    return false;
}

Triangle::Triangle(Vertex * v1, Vertex * v2, Vertex * v3) : Object() {
    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
}
