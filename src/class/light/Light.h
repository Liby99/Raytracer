#ifndef LIGHT_H
#define LIGHT_H

class Light {
private:
    
    // Private color
    Color color;
    vec3 fallOff;
    
public:
    
    // Constructor
    Light(Color c);
    
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
