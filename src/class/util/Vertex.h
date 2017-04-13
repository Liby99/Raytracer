#ifndef VERTEX_H
#define VERTEX_H

#include "util/Transform.h"

class Vertex {
private:
    
    // Basic parameter for vertex
    vec3 position;
    vec3 normal;
public:
    
    // Constructor
    Vertex(vec3 position);
    Vertex(vec3 position, vec3 normal);
    
    // Basic getter and setter
    vec3 getPosition() const;
    void setPosition(vec3 position);
    vec3 getNormal() const;
    void setNormal(vec3 normal);
};

#endif
