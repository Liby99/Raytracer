#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

#include "light/Light.h"

using namespace std;

class DirectionalLight : public Light {
protected:
    
    static vec3 DEFAULT_DIRECTION;
    
    //
    vec3 direction;
    
public:
    
    // Constructors
    DirectionalLight();
    DirectionalLight(Color color);
    DirectionalLight(Color color, vec3 direction);
    
    // Direction getter and setter
    vec3 getDirection() const;
    void setDirection(vec3 direction);
    
    // Inherited brightness and tolight
    virtual float getBrightness(Scene & scene, Intersection & intersection) const;
    virtual vec3 getToLightDirection(Intersection & intersection) const;
};

#endif
