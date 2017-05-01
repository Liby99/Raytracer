#ifndef VIEWER_H
#define VIEWER_H

#include "util/Color.h"
#include "image/Image.h"

#include <iostream>
#include <GLUT/glut.h>

class Viewer {
protected:
    
    // Default size parameter
    const static int DEFAULT_WIDTH = 800;
    const static int DEFAULT_HEIGHT = 600;
    
    // Viewer Parameter
    int width;
    int height;
    bool resizable;
    int glutWindow;
    
    // Helper Methods
    void setWindow(int window);
    
    // Normalize helper
    float normalWidth(int i);
    float normalHeight(int j);
    
public:
    
    // Constructor using size
    Viewer();
    Viewer(int width, int height);
    Viewer(int width, int height, const char * name);
    
    // Basic getter/setter
    int getWidth();
    int getHeight();
    void setWidth(int width);
    void setHeight(int height);
    
    // Event Listener
    void onInit(function<void()> func);
    void onDisplay(function<void()> func);
    void onResize(function<void(int, int)> func);
    void onKeyboard(function<void(unsigned char, int, int)> func);
    void onMouse(function<void(int, int, int, int)> func);
    void onHover(function<void(int, int)> func);
    void onDrag(function<void(int, int)> func);
    
    // Window command
    void init();
    void run();
    void focus();
    void close();
    
    // Pixel Operation
    void clear();
    void setImage(Image & image);
    void setPixel(int i, int j, Color c);
    Color getPixel(int i, int j);
};

#endif
