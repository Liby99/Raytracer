#ifndef COLOR_H
#define COLOR_H

#include "util/Transform.h"

#include <iostream>
#include <string>

using namespace std;

class Color {
private:
    
    static float MAX;
    static float DEFAULT_R;
    static float DEFAULT_G;
    static float DEFAULT_B;
    
    // Local variables
    float r;
    float g;
    float b;
public:
    
    // Constructors
    Color();
    Color(float r, float g, float b);
    
    // Getters
    float getR() const;
    float getG() const;
    float getB() const;
    
    // To int version
    int getIntR() const;
    int getIntG() const;
    int getIntB() const;
    
    // Setters
    void setR(float r);
    void setG(float g);
    void setB(float b);
    
    // To Int representation for bitmap
    int toInt() const;
    
    // Operators
    Color operator+(Color c) const;
    Color & operator+=(Color c);
    Color operator-(Color c) const;
    Color & operator-=(Color c);
    Color operator*(Color c) const;
    Color & operator*=(Color c);
    Color operator*(float scale) const;
    Color & operator*=(float scale);
    operator string() const;
    
    static Color parse(int c);
    
    friend std::ostream& operator<< (std::ostream & stream, Color & color);
};

#endif
