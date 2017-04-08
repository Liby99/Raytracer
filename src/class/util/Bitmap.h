#ifndef BITMAP_H
#define BITMAP_H

#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>

#include "util/Color.h"

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
