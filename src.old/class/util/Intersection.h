#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "util/Transform.h"
#include "util/Ray.h"

class Object;

class Intersection {
private:
    
    // Reference to ray and object
    const Ray * ray;
    const Object * object;
    
    // Intersection parameters
    bool hitFlag;
    float t;
    vec3 position;
    vec3 normal;
    
public:
    
    // Constructor
    Intersection(const Ray & ray);
    
    // Reference Getter and setter
    const Object & getObject() const;
    void setObject(const Object & object);
    const Ray & getRay() const;
    void setRay(const Ray & ray);
    
    // Parameter Getter and setter
    bool hit() const;
    void setHit(bool hit);
    float getT() const;
    void setT(float t);
    vec3 getPosition() const;
    void setPosition(vec3 position);
    vec3 getNormal() const;
    void setNormal(vec3 normal);
    
    float getDistanceToOrigin() const;
    bool needUpdate(float t) const;
    bool update(float t, const vec3 position, const vec3 normal);
    
    void transform(mat4 transform);
};

#endif
