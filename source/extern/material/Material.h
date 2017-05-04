#ifndef MATERIAL_H
#define MATERIAL_H

#include "util/Color.h"
#include "util/Intersection.h"
#include "util/Ray.h"
#include <vector>
#include <utility>

using namespace std;

class Material {
public:
    
    // Constructor
    Material();
    
    // Virtual methods
    virtual vector<pair<Ray, Color>> reflection(Intersection & i, int amount);
    virtual Color emission();
};

#endif
