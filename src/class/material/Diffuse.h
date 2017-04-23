#ifndef DIFFUSE_H
#define DIFFUSE_H

#include "material/Material.h"

using namespace std;

class Diffuse : public Material {
private:
    static Color DEFAULT_DIFFUSE;
    Color diffuse;
    virtual Color getShadingColor(Scene & scene, Intersection & intersection) const;
public:
    Diffuse();
    Diffuse(Color diffuse);
    Color getDiffuse() const;
    void setDiffuse(Color ambient);
};

#endif
