#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTINOAL_LIGHT_H

class DirectionalLight : public Light {
protected:
    
    const static vec3 DEFAULT_DIRECTION;
    
    //
    vec3 direction;
    
public:
    
    // Constructors
    DirectionalLight();
    DirectionalLight(Color color);
    DirectionalLight(Color color, vec3 direction);
    
    // Direction getter and setter
    vec3 getDirection();
    void setDirection(vec3 direction);
    
    // Inherited brightness and tolight
    virtual float getBrightness(Scene & scene, Intersection & intersection);
    virtual vec3 getToLightDirection(Intersection & intersection);
};

#endif;
