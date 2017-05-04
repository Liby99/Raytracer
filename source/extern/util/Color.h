#ifndef COLOR_H
#define COLOR_H

#include "util/Transform.h"

#include <iostream>
#include <string>

using namespace std;

class Color {
private:
    
    const static float MAX;
    const static float DEFAULT_R;
    const static float DEFAULT_G;
    const static float DEFAULT_B;
    
    // Local variables
    float r;
    float g;
    float b;
public:
    
    // Constructors
    Color();
    Color(float r, float g, float b);
    
    // Getters
    float getR();
    float getG();
    float getB();
    
    // To int version
    int getIntR();
    int getIntG();
    int getIntB();
    
    // Setters
    void setR(float r);
    void setG(float g);
    void setB(float b);
    
    // To Int representation for bitmap
    int toInt() ;
    
    // Operators
    Color operator+(Color c);
    Color & operator+=(Color c);
    Color operator-(Color c);
    Color & operator-=(Color c);
    Color operator*(Color c);
    Color & operator*=(Color c);
    Color operator*(float scale);
    Color & operator*=(float scale);
    operator string();
    
    static Color parse(int c);
    
    friend std::ostream& operator<< (std::ostream & stream, Color & color);
};

#endif