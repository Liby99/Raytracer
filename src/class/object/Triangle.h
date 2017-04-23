#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "object/Object.h"
#include "util/Vertex.h"
#include "util/Ray.h"

#include <stdexcept>

class Triangle : public Object {
private:
    
    // Vertices of triangle
    Vertex * v0;
    Vertex * v1;
    Vertex * v2;
    
    // Helper methods
    vec3 getBaryCentric(vec3 position) const;
    
protected:
    
    // Intersection with ray
    virtual bool updateIntersect(Ray & ray, Intersection & intersection) const;
    
public:
    
    // Constructor
    Triangle(Vertex * v0, Vertex * v1, Vertex * v2);
    
    // Getters
    Vertex & getVertex(int i);
    Vertex & getV0() const;
    Vertex & getV1() const;
    Vertex & getV2() const;
};

#endif
