#ifndef MESH_OBJECT_H
#define MESH_OBJECT_H

#include "object/Object.h"
#include "object/Triangle.h"
#include "util/Vertex.h"

class MeshObject : public Object {
private:
    
    vec3 getMinCorner();
    vec3 getMaxCorner();
    
protected:
    
    // Vertex and Triangle Array
    vector<Vertex *> vertices;
    vector<Triangle *> triangles;
    
    // Intersect
    virtual bool updateIntersect(Ray & ray, Intersection & intersection) const;
    
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
    
    // Load object from file
    bool loadPly(char * filename);
    void smooth();
};

#endif
