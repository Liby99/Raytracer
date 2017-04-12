#ifndef MESH_OBJECT_H
#define MESH_OBJECT_H

#include "object/Object.h"
#include "object/Triangle.h"
#include "util/Vertex.h"

class MeshObject : public Object {
protected:
    
    // Vertex and Triangle Array
    vector<Vertex *> vertices;
    vector<Triangle *> triangles;
    
    // Intersect
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
    
public:
    
    // Constructor and Destructor
    MeshObject();
    ~MeshObject();
    
    // Vertex and Triangle Manipulation
    void addVertex(vec3 position);
    void addVertex(vec3 position, vec3 normal);
    void addTriangle(int i1, int i2, int i3);
    
    // Destructor helper methods
    void clear();
    void clearVertices();
    void clearTriangles();
};

#endif
