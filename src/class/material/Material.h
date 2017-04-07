#ifndef MATERIAL_H
#define MATERIAL_H

class Material {
private:
    float opacity;
public:
    void setOpacity(float opacity);
    virtual Color shade(Scene & scene, Intersection & intersection);
};

#endif
