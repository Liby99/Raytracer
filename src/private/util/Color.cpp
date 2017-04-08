#include "util/Color.h"

using namespace std;

const float Color::MAX = 255.0f;
const float Color::DEFAULT_R = 0;
const float Color::DEFAULT_G = 0;
const float Color::DEFAULT_B = 0;

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
    return int(r * MAX) & 0xff;
}

int Color::getIntG() {
    return int(g * MAX) & 0xff;
}

int Color::getIntB() {
    return int(b * MAX) & 0xff;
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
    return (getIntR() << 16) | (getIntG() << 8) | getIntB();
}

Color Color::operator+(Color c) {
    return Color(fmin(1.0f, r + c.r), fmin(1.0f, g + c.g), fmin(1.0f, b + c.b));
}

Color & Color::operator+=(Color c) {
    r += c.r;
    g += c.g;
    b += c.b;
    return *this;
}

Color Color::operator-(Color c) {
    return Color(fmax(0.0f, r - c.r), fmax(0.0f, g - c.g), fmax(0.0f, b - c.b));
}

Color & Color::operator-=(Color c) {
    r -= c.r;
    g -= c.g;
    b -= c.b;
    return *this;
}

Color Color::operator*(Color c) {
    return Color(r * c.r, g * c.g, b * c.b);
}

Color & Color::operator*=(Color c) {
    r *= c.r;
    g *= c.g;
    b *= c.b;
    return *this;
}

Color Color::operator*(float scale) {
    return Color(r * scale, g * scale, b * scale);
}

Color & Color::operator*=(float scale) {
    r *= scale;
    g *= scale;
    b *= scale;
    return *this;
}

Color::operator string() {
    return "rgb(" + to_string(getIntR()) + ", " +
                    to_string(getIntG()) + ", " +
                    to_string(getIntB()) + ")";
}

Color Color::parse(int c) {
    int r = (float) ((c >> 16) & 0xff) / MAX;
    int g = (float) ((c >> 8) & 0xff) / MAX;
    int b = (float) (c & 0xff) / MAX;
    return Color(r, g, b);
}
