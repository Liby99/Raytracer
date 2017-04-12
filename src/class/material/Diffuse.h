#ifndef DIFFUSE_H
#define DIFFUSE_H

#include "material/Material.h"

using namespace std;

class Diffuse : public Material {
private:
    const static Color DEFAULT_DIFFUSE;
    Color diffuse;
    virtual Color getShadingColor(const Scene & scene, const Intersection & intersection) const;
public:
    Diffuse();
    Diffuse(const Color diffuse);
    Color getDiffuse() const;
    void setDiffuse(const Color ambient);
};

#endif
