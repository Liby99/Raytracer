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
    return Color(bound(r + c.r), bound(g + c.g), bound(b + c.b));
}

Color & Color::operator+=(Color c) {
    r = bound(r + c.r);
    g = bound(g + c.g);
    b = bound(b + c.b);
    return *this;
}

Color Color::operator-(Color c) {
    return Color(bound(r - c.r), bound(g - c.g), bound(b - c.b));
}

Color & Color::operator-=(Color c) {
    r = bound(r - c.r);
    g = bound(g - c.g);
    b = bound(b - c.b);
    return *this;
}

Color Color::operator*(Color c) {
    return Color(bound(r * c.r), bound(g * c.g), bound(b * c.b));
}

Color & Color::operator*=(Color c) {
    r = bound(r * c.r);
    g = bound(g * c.g);
    b = bound(b * c.b);
    return *this;
}

Color Color::operator*(float scale) {
    return Color(bound(r * scale), bound(g * scale), bound(b * scale));
}

Color & Color::operator*=(float scale) {
    r = bound(r * scale);
    g = bound(g * scale);
    b = bound(b * scale);
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
