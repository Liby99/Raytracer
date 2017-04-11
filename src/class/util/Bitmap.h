#ifndef BITMAP_H
#define BITMAP_H

#include <iostream>

#include "util/Color.h"

using namespace std;

class Bitmap {
private:
    
    // Basic size parameter
    int width;
    int height;
    
    // Image pixels
    int * pixel;
public:
    
    // Constructor and Destructor
    Bitmap(int x,int y);
    ~Bitmap();
    
    // Getter of width and height
    int getWidth();
    int getHeight();
    
    // Pixel getter and setter
    Color getPixel(int x, int y);
    void setPixel(int x, int y, Color color);
    
    // Save image api
    bool saveImage(const char * filename);
};

#endif
