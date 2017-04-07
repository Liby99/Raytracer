#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H

class SpotLight : public Light {
private:
    vec3 position;
    vec3 target;
    float angle;
public:
    SpotLight(Color color, vec3 position, vec3 target, float angle);
    vec3 getPosition();
    vec3 getTarget();
    float getAngle();
};

#endif
