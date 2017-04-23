#include "util/Orientable.h"

vec3 Orientable::NORMALS[] = {
    vec3(1, 0, 0),
    vec3(-1, 0, 0),
    vec3(0, 1, 0),
    vec3(0, -1, 0),
    vec3(0, 0, 1),
    vec3(0, 0, -1)
};

int Orientable::X_POSITIVE = 0;
int Orientable::X_NEGATIVE = 1;
int Orientable::Y_POSITIVE = 2;
int Orientable::Y_NEGATIVE = 3;
int Orientable::Z_POSITIVE = 4;
int Orientable::Z_NEGATIVE = 5;

int Orientable::DEFAULT_ORIENTATION = Orientable::Y_POSITIVE;

Orientable::Orientable() {
    setOrientation(DEFAULT_ORIENTATION);
}

Orientable::Orientable(int orientation) {
    setOrientation(orientation);
}

int Orientable::getAxis() {
    return orientation / 2;
}

int Orientable::getOrientation() {
    return orientation;
}

void Orientable::setOrientation(int orientation) {
    this->orientation = orientation;
}
