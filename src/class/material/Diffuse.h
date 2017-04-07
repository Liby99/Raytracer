#ifndef DIFFUSE_H
#define DIFFUSE_H

class Diffuse : public Material {
private:
    Color diffuse;
public:
    Diffuse(Color diffuse);
    virtual Color shade(Scene & scene, Intersection & intersection);
};

#endif
