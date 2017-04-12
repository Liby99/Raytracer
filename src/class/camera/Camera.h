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
    Camera(const vec3 position, const vec3 focalPoint);
    Camera(const vec3 position, const vec3 focalPoint, const vec3 up);
    
    void lookAt(const vec3 position, const vec3 focalPoint);
    void lookAt(const vec3 position, const vec3 focalPoint, const vec3 up);
    void setPosition(const vec3 position);
    void setFocalPoint(const vec3 focalPoint);
    void setUp(const vec3 up);
    
    vec3 getPosition() const;
    vec3 getFocalPoint() const;
    vec3 getUp() const;
    
    void setResolution(const int width, const int height);
    void setWidth(const int width);
    void setHeight(const int height);
    void setFovy(const float fovy);
    
    // Render Functions
    virtual Bitmap render(const Scene & scene) const;
};

#endif
