#ifndef COLOR_H
#define COLOR_H

class Color {
private:
    
    const static float MAX;
    const static unsigned int MASK;
    const static float DEFAULT_R;
    const static float DEFAULT_G;
    const static float DEFAULT_B;
    const static int R_POSITION;
    const static int G_POSITION;
    const static int B_POSITION;
    
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
    int toInt();
    
    // Operators
    Color operator+(Color c);
    Color operator-(Color c);
    Color operator*(Color c);
    Color operator*(float scale);
    
    static Color parse(int c);
};

#endif
