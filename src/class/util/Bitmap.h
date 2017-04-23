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
    int getWidth() const;
    int getHeight() const;
    
    // Pixel getter and setter
    Color getPixel(int x, int y) const;
    void setPixel(int x, int y, Color color);
    
    // Save image api
    bool saveImage(char * filename) const;
};

#endif
