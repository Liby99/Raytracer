#ifndef AMBIENT_H
#define AMBIENT_H

#include "material/Material.h"

class Ambient : public Material {
private:
    Color ambient;
public:
    Ambient(Color ambient);
    Color getAmbient();
    void setAmbient(Color ambient);
    virtual Color shade(Scene & scene, Intersection & intersection);
};

#endif;
