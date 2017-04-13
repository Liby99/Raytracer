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
    virtual bool updateIntersect(const Ray & ray, Intersection & intersection) const;
    
public:
    
    // Constructor and Destructor
    MeshObject();
    ~MeshObject();
    
    // Vertex and Triangle Manipulation
    void addVertex(const vec3 position);
    void addVertex(const vec3 position, const vec3 normal);
    void addTriangle(int i1, int i2, int i3);
    
    // Destructor helper methods
    void clear();
    void clearVertices();
    void clearTriangles();
};

#endif
