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
    const static vec3 DEFAULT_POSITION;
    const static vec3 DEFAULT_FOCAL_POINT;
    const static vec3 DEFAULT_UP;
    const static int DEFAULT_WIDTH;
    const static int DEFAULT_HEIGHT;
    const static float DEFAULT_FOVY;
    
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
    
    vec3 getPosition() ;
    vec3 getFocalPoint() ;
    vec3 getUp() ;
    
    void setResolution(int width, int height);
    void setWidth(int width);
    void setHeight(int height);
    void setFovy(float fovy);
    
    // Render Functions
    virtual Bitmap render(Scene & scene) ;
};

#endif
