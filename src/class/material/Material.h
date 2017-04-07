#ifndef MATERIAL_H
#define MATERIAL_H

#include "util/Color.h"

class Material {
protected:
    const static float DEFAULT_OPACITY;
    float opacity;
public:
    Material();
    void setOpacity(float opacity);
    float getOpacity();
    virtual Color shade(Scene & scene, Intersection & intersection);
};

#endif
