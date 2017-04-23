#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

#include "light/Light.h"

using namespace std;

class DirectionalLight : public Light {
protected:
    
    const static vec3 DEFAULT_DIRECTION;
    
    //
    vec3 direction;
    
public:
    
    // Constructors
    DirectionalLight();
    DirectionalLight(const Color color);
    DirectionalLight(const Color color, const vec3 direction);
    
    // Direction getter and setter
    vec3 getDirection() const;
    void setDirection(const vec3 direction);
    
    // Inherited brightness and tolight
    virtual float getBrightness(const Scene & scene, const Intersection & intersection) const;
    virtual vec3 getToLightDirection(const Intersection & intersection) const;
};

#endif
