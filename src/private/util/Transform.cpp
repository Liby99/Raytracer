#include "util/Transform.h"

vec3 maxVec(vec3 a, vec3 b) {
    return vec3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
}

vec3 minVec(vec3 a, vec3 b) {
    return vec3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
}

mat4 Transform::rotate(float degrees, vec3& axis) {
    float x = axis.x,
        y = axis.y,
        z = axis.z,
        cosine = cos(degrees / 180 * pi),
        sine = sin(degrees / 180 * pi),
        a = cosine + x * x * (1 - cosine),
        b = x * y * (1 - cosine) - z * sine,
        c = x * z * (1 - cosine) + y * sine,
        d = y * x * (1 - cosine) + z * sine,
        e = cosine + y * y * (1 - cosine),
        f = y * z * (1 - cosine) - x * sine,
        g = z * x * (1 - cosine) - y * sine,
        h = z * y * (1 - cosine) + x * sine,
        i = cosine + z * z * (1 - cosine);
    return mat4(a, d, g, 0, b, e, h, 0, c, f, i, 0, 0, 0, 0, 1);
}

mat4 Transform::scale(float &sx, float &sy, float &sz) {
    return mat4(sx, 0, 0, 0,
                0, sy, 0, 0,
                0, 0, sz, 0,
                0, 0, 0, 1);
}

mat4 Transform::translate(float &tx, float &ty, float &tz) {
    return mat4(1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                tx, ty, tz, 1);
}
