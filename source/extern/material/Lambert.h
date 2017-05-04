#ifndef LAMBERT_H
#define LAMBERT_H

#include "material/Material.h"
#include "util/Sampler.h"

class Lambert {
private:
    
    Color color;
    
public:
    
    // Constructor
    Lambert();
    Lambert(Color color);
    
    void setColor(Color color);
    Color getColor();
    
    // Virtual methods
    virtual vector<pair<Ray, Color>> reflection(Intersection & i, int amount);
    virtual Color emission();
};

#endif
