#ifndef MESH_OBJECT_H
#define MESH_OBJECT_H

#include "object/Object.h"
#include "object/Triangle.h"
#include "util/Vertex.h"

class MeshObject : public Object {
private:
    
    // Vertex and Triangle Array
    vector<Vertex *> vertices;
    vector<Triangle *> triangles;
    
    // Destructor helper methods
    void clearVertices();
    void clearTriangles();
public:
    
    // Constructor and Destructor
    MeshObject();
    ~MeshObject();
    
    // Vertex and Triangle Manipulation
    void addVertex(vec3 position);
    void addVertex(vec3 position, vec3 normal);
    void addTriangle(int i1, int i2, int i3);
    
    // Intersect
    virtual bool intersect(Ray & ray, Intersection & intersection);
};

#endif
