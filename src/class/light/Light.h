#ifndef LIGHT_H
#define LIGHT_H

class Light {
protected:
    
    const static Color DEFAULT_COLOR;
    const static float DEFAULT_INTENSITY;
    
    // Private color
    Color color;
    
public:
    
    // Constructor
    Light();
    Light(Color c);
    Light(Color c, vec3 fallOff);
    
    // Color related setter getter
    Color getColor();
    void setColor(Color color);
    float getIntensity();
    void setIntensity(float intensity);
    
    // Illuminate
    virtual float getBrightness(Intersection & intersection);
    virtual vec3 getToLightDirection(Intersection & intersection);
};

#endif
