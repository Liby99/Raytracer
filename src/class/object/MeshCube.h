#ifndef MESH_CUBE_H
#define MESH_CUBE_H

#include "object/MeshObject.h"
#include "object/Cube.h"

class MeshCube : public Cube {
private:
    
    // Mesh instance. Adapter Structure
    MeshObject mesh;
    
    // Helper functions of constructing the cube
    void clear();
    void construct();
    void reconstruct();
    
protected:
    
    // Inherited intersect method
    virtual bool updateIntersect(const Ray & ray, Intersection & intersection) const;
    
public:
    
    // Constructor
    MeshCube();
    MeshCube(const float width, const float height, const float length);
    
    // Basic getter and setter
    virtual void setWidth(const float width);
    virtual void setHeight(const float height);
    virtual void setLength(const float length);
};

#endif
