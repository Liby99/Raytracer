#ifndef SPECULAR_H
#define SPECULAR_H

using namespace std;

class Specular : public Material {
private:
    Color specular;
public:
    Specular(Color specular);
    virtual Color shade(Scene & scene, Intersection & intersection);
};

#endif
