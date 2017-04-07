#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "util/Transform.h"

class PointLight : public Light {
protected:
    
    // Default Fall Off
    const static vec3 DEFAULT_FALL_OFF;
    const static vec3 DEFAULT_POSITION;
    
    // Basic Variables
    vec3 position;
    vec3 fallOff;
    
public:
    
    // Constructor
    PointLight(Color color);
    PointLight(Color color, vec3 position);
    
    // Position setter getter
    vec3 getPosition();
    void setPosition(vec3 position);
    
    // Fall Off related setter getter
    vec3 getFallOff();
    void setFallOff(vec3 fallOff);
    
    // Inherited brightness and tolight
    virtual float getBrightness(Intersection & intersection);
    virtual vec3 getToLightDirection(Intersection & intersection);
};

#endif
