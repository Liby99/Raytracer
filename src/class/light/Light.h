#ifndef LIGHT_H
#define LIGHT_H

class Light {
private:
    
    const static Color DEFAULT_COLOR;
    const static vec3 DEFAULT_FALL_OFF;
    
    // Private color
    Color color;
    vec3 fallOff;
    
public:
    
    // Constructor
    Light();
    Light(Color c);
    Light(Color c, vec3 fallOff);
    
    // Color related setter getter
    Color getColor();
    void setColor(Color color);
    
    // Fall Off related setter getter
    vec3 getFallOff();
    void setFallOff(vec3 fallOff);
    
    // Illuminate
    virtual float illuminate(Intersection & intersection);
};

#endif
