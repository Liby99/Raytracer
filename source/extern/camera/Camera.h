#ifndef CAMERA_H
#define CAMERA_H

#include <functional>

#include "scene/Scene.h"
#include "image/Image.h"
#include "util/Color.h"
#include "util/Transform.h"
#include "util/Ray.h"

using namespace std;

class Camera {
protected:
    
    // Constants
    const static vec3 DEFAULT_POSITION;
    const static vec3 DEFAULT_FOCAL_POINT;
    const static vec3 DEFAULT_UP;
    const static int DEFAULT_WIDTH;
    const static int DEFAULT_HEIGHT;
    const static float DEFAULT_FOVY;
    
    // Callback Functions
    function<void(int, int, Color)> onPixelUpdateCallback;
    
    // Private position vectors
    vec3 position;
    vec3 focalPoint;
    vec3 up;
    int width;
    int height;
    float fovy;
    
    // Advanced Settings
    bool depthOfField;
    float focalDistance;
    float aperture;
    float shutter;
    
public:
    
    // Constructors
    Camera();
    Camera(vec3 position, vec3 focalPoint);
    Camera(vec3 position, vec3 focalPoint, vec3 up);
    
    void lookAt(vec3 position, vec3 focalPoint);
    void lookAt(vec3 position, vec3 focalPoint, vec3 up);
    void setPosition(vec3 position);
    void setFocalPoint(vec3 focalPoint);
    void setUp(vec3 up);
    
    vec3 getPosition();
    vec3 getFocalPoint();
    vec3 getUp();
    
    void setResolution(int width, int height);
    void setWidth(int width);
    void setHeight(int height);
    void setFovy(float fovy);
    
    void onPixelUpdate(function<void(int, int, Color)> func);
    
    // Render Functions
    virtual Image render(Scene & scene);
};

#endif