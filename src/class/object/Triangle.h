#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "object/Object.h"
#include "util/Vertex.h"
#include "util/Ray.h"

class Triangle : public Object {
private:
    
    // Vertices of triangle
    Vertex * v1;
    Vertex * v2;
    Vertex * v3;
    
    // Helper methods
    vec3 getBaryCentric(vec3 position);
protected:
    
    // Intersection with ray
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
public:
    
    // Constructor
    Triangle(Vertex * v1, Vertex * v2, Vertex * v3);
};

#endif
