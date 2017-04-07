#ifndef AMBIENT_H
#define AMBIENT_H

class Ambient {
private:
    Color ambient;
public:
    Ambient(Color ambient);
    virtual Color shade(Scene & scene, Intersection & intersection);
};

#endif;
