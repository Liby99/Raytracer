#ifndef DIFFUSE_H
#define DIFFUSE_H

#include "material/Material.h"

using namespace std;

class Diffuse : public Material {
protected:
    
    //
    const static Color DEFAULT_DIFFUSE;
    Color diffuse;
    
    // Virtual methods
    virtual Color getShadingColor(Scene & scene, Intersection & intersection);
    
public:
    
    // Constructors
    Diffuse();
    Diffuse(Color diffuse);
    Color getDiffuse();
    void setDiffuse(Color ambient);
};

#endif
