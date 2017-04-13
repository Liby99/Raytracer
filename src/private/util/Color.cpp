#include "util/Color.h"

using namespace std;

const float Color::MAX = 255.0f;
const float Color::DEFAULT_R = 0;
const float Color::DEFAULT_G = 0;
const float Color::DEFAULT_B = 0;

float bound(float f) {
    return (f <= 0) ? 0 : (f >= 1) ? 1 : f;
}

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

float Color::getR() const {
    return r;
}

float Color::getG() const {
    return g;
}

float Color::getB() const {
    return b;
}

int Color::getIntR() const {
    return int(bound(r) * MAX) & 0xff;
}

int Color::getIntG() const {
    return int(bound(g) * MAX) & 0xff;
}

int Color::getIntB() const {
    return int(bound(b) * MAX) & 0xff;
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

int Color::toInt() const {
    return (getIntR() << 16) | (getIntG() << 8) | getIntB();
}

Color Color::operator+(Color c) const {
    return Color(r + c.r, g + c.g, b + c.b);
}

Color & Color::operator+=(Color c) {
    r += c.r;
    g += c.g;
    b += c.b;
    return *this;
}

Color Color::operator-(Color c) const {
    return Color(r - c.r, g - c.g, b - c.b);
}

Color & Color::operator-=(Color c) {
    r = r - c.r;
    g = g - c.g;
    b = b - c.b;
    return *this;
}

Color Color::operator*(Color c) const {
    return Color(r * c.r, g * c.g, b * c.b);
}

Color & Color::operator*=(Color c) {
    r *= c.r;
    g *= c.g;
    b *= c.b;
    return *this;
}

Color Color::operator*(float scale) const {
    return Color(r * scale, g * scale, b * scale);
}

Color & Color::operator*=(float scale) {
    r *= scale;
    g *= scale;
    b *= scale;
    return *this;
}

Color::operator string() const {
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

std::ostream & operator<< (std::ostream & stream, const Color & color) {
    stream << (string)color;
    return stream;
}
