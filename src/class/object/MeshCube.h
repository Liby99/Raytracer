#ifndef MESH_CUBE_H
#define MESH_CUBE_H

#include "object/MeshObject.h"

class MeshCube : public Object {
private:
    MeshObject mesh;
public:
    MeshCube(float width, float height, float length);
    virtual bool intersect(Ray & ray, Intersection & intersection);
};

#endif
