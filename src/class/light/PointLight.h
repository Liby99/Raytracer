#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

class PointLight : public Light {
private:
    vec3 position;
public:
    PointLight(Color color, vec3 position);
    vec3 getPosition();
};

#endif
