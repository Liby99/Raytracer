#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H

#include "light/PointLight.h"

using namespace std;

class SpotLight : public PointLight {
protected:
    
    // Constant default value
    static vec3 DEFAULT_FALL_OFF;
    static vec3 DEFAULT_TARGET;
    static float DEFAULT_ANGLE;
    
    //
    vec3 target;
    float angle;
    
public:
    
    // Constructors
    SpotLight();
    SpotLight(Color color, vec3 position, vec3 target, float angle);
    
    // Basic getter and setter
    vec3 getPosition() const;
    void setPosition(vec3 position);
    vec3 getTarget() const;
    void setTarget(vec3 target);
    float getAngle() const;
    void setAngle(float angle);
    
    // Illuminate
    virtual float getBrightness(Scene & scene, Intersection & intersection) const;
    virtual vec3 getToLightDirection(Intersection & intersection) const;
};

#endif
