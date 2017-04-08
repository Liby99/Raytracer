#ifndef MESH_CUBE_H
#define MESH_CUBE_H

#include "object/MeshObject.h"

class MeshCube : public Object {
private:
    MeshObject mesh;
    void clear();
    void construct();
    void reconstruct();
protected:
    virtual bool updateIntersect(Ray & ray, Intersection & intersection);
public:
    MeshCube(float width, float height, float length);
    float getWidth();
    void setWidth(float width);
    float getHeight();
    void setHeight(float height);
    float getLength();
    void setLength(float length);
};

#endif
