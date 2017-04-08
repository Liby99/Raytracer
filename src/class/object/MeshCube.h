#ifndef MESH_CUBE_H
#define MESH_CUBE_H

#include "object/MeshObject.h"

class MeshCube : public Object {
private:
    
    // Mesh instance. Adapter Structure
    MeshObject mesh;
    
    // Basic parameters
    float width;
    float height;
    float length;
    
    // Helper functions of constructing the cube
    void clear();
    void construct();
    void reconstruct();
    
protected:
    
    // Inherited intersect method
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
public:
    
    // Constructor
    MeshCube(float width, float height, float length);
    
    // Basic getter and setter
    float getWidth();
    void setWidth(float width);
    float getHeight();
    void setHeight(float height);
    float getLength();
    void setLength(float length);
};

#endif
