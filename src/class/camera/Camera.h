#ifndef CAMERA_H
#define CAMERA_H

#include "scene/Scene.h"
#include "util/Color.h"
#include "util/Transform.h"
#include "util/Bitmap.h"
#include "util/Ray.h"

using namespace std;

class Camera {
protected:
    
    // Constants
    static vec3 DEFAULT_POSITION;
    static vec3 DEFAULT_FOCAL_POINT;
    static vec3 DEFAULT_UP;
    static int DEFAULT_WIDTH;
    static int DEFAULT_HEIGHT;
    static float DEFAULT_FOVY;
    
    // Private position vectors
    vec3 position;
    vec3 focalPoint;
    vec3 up;
    int width;
    int height;
    float fovy;
    
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
    
    vec3 getPosition() const;
    vec3 getFocalPoint() const;
    vec3 getUp() const;
    
    void setResolution(int width, int height);
    void setWidth(int width);
    void setHeight(int height);
    void setFovy(float fovy);
    
    // Render Functions
    virtual Bitmap render(Scene & scene) const;
};

#endif
