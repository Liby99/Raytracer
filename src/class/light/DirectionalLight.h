#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTINOAL_LIGHT_H

class DirectionalLight : public Light {
private:
    vec3 direction;
public:
    DirectionalLight(Color color, vec3 direction);
    vec3 getDirection();
};

#endif;
