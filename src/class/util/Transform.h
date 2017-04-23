#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

typedef glm::mat2 mat2;
typedef glm::mat3 mat3;
typedef glm::mat4 mat4;
typedef glm::vec2 vec2;
typedef glm::vec3 vec3;
typedef glm::vec4 vec4;
float pi = 3.14159265f;

int maxAxis(vec3 v);
vec3 maxVec(vec3 a, vec3 b);
vec3 minVec(vec3 a, vec3 b);

class Transform {
public:
    static mat4 rotate(float degrees, vec3& axis);
    static mat4 scale(float &sx, float &sy, float &sz);
    static mat4 translate(float &tx, float &ty, float &tz);
};

#endif
