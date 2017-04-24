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

const float pi = 3.14159265f;

int maxAxis(const vec3 & v);
vec3 maxVec(const vec3 & a, const vec3 & b);
vec3 minVec(const vec3 & a, const vec3 & b);

class Transform {
public:
    static mat4 rotate(const float degrees, const vec3& axis);
    static mat4 scale(const float &sx, const float &sy, const float &sz);
    static mat4 translate(const float &tx, const float &ty, const float &tz);
};

#endif
