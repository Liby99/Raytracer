#ifndef LUMINANCE_H
#define LUMINANCE_H

#include "material/Material.h"

class Luminance : public Material {
private:
    Color color;
public:
    
    //
    Luminance();
    Luminance(Color color);
    
    //
    void setColor(Color color);
    Color getColor();
    
    //
    virtual Color computeReflection(Intersection & i, Ray & out);
    virtual vector<pair<Ray, Color>> reflection(Intersection & i, int amount);
    virtual Color emission();
};

#endif
