#ifndef DIFFUSE_H
#define DIFFUSE_H

#include "material/Material.h"

class Diffuse : public Material {
private:
    Color diffuse;
public:
    Diffuse(Color diffuse);
    Color getDiffuse();
    void setDiffuse(Color ambient);
    virtual Color shade(Scene & scene, Intersection & intersection);
};

#endif
