#include "util/Color.h"

Color::MAX = 256.0f;
Color::MASK = -1 << ((sizeof(int) - 1) * 8) >> ((sizeof(int) - 1) * 8);
Color::DEFAULT_R = 0;
Color::DEFAULT_G = 0;
Color::DEFAULT_B = 0;
Color::R_POSITION = 16;
Color::G_POSITION = 8;
Color::B_POSITION = 0;

Color::Color() {
    setR(DEFAULT_R);
    setG(DEFAULT_G);
    setB(DEFAULT_B);
}

Color::Color(float r, float g, float b) {
    setR(r);
    setG(g);
    setB(b);
}

float Color::getR() {
    return r;
}

float Color::getG() {
    return g;
}

float Color::getB() {
    return b;
}

int Color::getIntR() {
    return int(r * MAX);
}

int Color::getIntG() {
    return int(g * MAX);
}

int Color::getIntB() {
    return int(b * MAX);
}

void Color::setR(float r) {
    this->r = r;
}

void Color::setG(float g) {
    this->g = g;
}

void Color::setB(float b) {
    this->b = b;
}

int Color::toInt() {
    return (getIntR() << R_POSITION) |
           (getIntG() << G_POSITION) |
           (getIntB() << B_POSITION);
}

Color Color::operator+(Color c) {
    return Color(min(1, r + c.r), min(1, g + c.g), min(1, b + c.b));
}

Color Color::operator-(Color c) {
    return Color(max(0, r - c.r), max(0, g - c.g), max(0, b - c.b));
}

Color Color::operator*(Color c) {
    return Color(r * c.r, g * c.g, b * c.b);
}

Color Color::operator*(float scale) {
    return Color(r * scale, g * scale, b * scale);
}

static Color Color::parse(int c) {
    int r = ((c >> R_POSITION) & MASK) / MAX;
    int g = ((g >> G_POSITION) & MASK) / MAX;
    int b = ((b >> B_POSITION) & MASK) / MAX;
    return Color(r, g, b);
}
