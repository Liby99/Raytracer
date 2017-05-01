#ifndef GLUT_WINDOW_H
#define GLUT_WINDOW_H

#include <GLUT/glut.h>
#include <iostream>
#include <functional>
#include <map>

using namespace std;

class GlutWindow {
protected:
    
    const static int DEFAULT_WIDTH = 800;
    const static int DEFAULT_HEIGHT = 600;
    
    // Static Fields to get the instances
    static map<int, GlutWindow *> windows;
    static int activeWindow;
    
    //
    static void staticStart();
    
    // Instance Variables
    int currWindow;
    int width;
    int height;
    bool displaySettled;
    
public:

    // Instance Listeners
    function<void()> onInitListener;
    function<void()> onDisplayListener;
    // function<void(int, int)> onResizeListener;
    // function<void(unsigned char, int, int)> onKeyboardListener;
    // function<void(int, int, int, int)> onMouseListener;
    // function<void(int, int)> onHoverListener;
    // function<void(int, int)> onDragListener;
    
    // Constructors
    GlutWindow();
    GlutWindow(int width, int height);
    GlutWindow(int width, int height, const char * name);
    ~GlutWindow();
    
    void setWidth(int width);
    void setHeight(int height);
    
    int getWidth();
    int getHeight();
    
    void onInit(function<void()> func);
    void onDisplay(function<void()> func);
    void onResize(function<void(int, int)> func);
    void onKeyboard(function<void(unsigned char, int, int)> func);
    void onMouse(function<void(int, int, int, int)> func);
    void onHover(function<void(int, int)> func);
    void onDrag(function<void(int, int)> func);
    
    void start();
};

#endif
