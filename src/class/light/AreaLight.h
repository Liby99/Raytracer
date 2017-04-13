#ifndef AREA_LIGHT_H
#define AREA_LIGHT_H

#include "light/PointLight.h"
#include "util/Orientable.h"

class AreaLight : public PointLight, public Orientable {
protected:
    
    //
    const static float DEFAULT_SIZE;
    
    //
    float width;
    float height;
public:
    AreaLight(Color color, )
};

#endif
