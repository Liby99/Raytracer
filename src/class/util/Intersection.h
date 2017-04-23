#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "util/Transform.h"
#include "util/Ray.h"

class Object;

class Intersection {
private:
    
    // Reference to ray and object
    Ray * ray;
    Object * object;
    
    // Intersection parameters
    bool hitFlag;
    float t;
    vec3 position;
    vec3 normal;
    
public:
    
    // Constructor
    Intersection(Ray & ray);
    
    // Reference Getter and setter
    Object & getObject() const;
    void setObject(Object & object);
    Ray & getRay() const;
    void setRay(Ray & ray);
    
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
    bool update(float t, vec3 position, vec3 normal);
    
    void transform(mat4 transform);
};

#endif
