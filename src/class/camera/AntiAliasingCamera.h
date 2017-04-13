#ifndef ANTI_ALIASING_CAMERA_H
#define ANTI_ALIASING_CAMERA_H

#include "camera/Camera.h"

class AntiAliasingCamera : public Camera {
protected:
    
    // Default constants
    const static int DEFAULT_LEVEL;
    
    // Division per pixel. Will be squared
    int level;
    
public:
    
    AntiAliasingCamera();
    AntiAliasingCamera(const int level);
    AntiAliasingCamera(const vec3 position, const vec3 focalPoint, const int level);
    AntiAliasingCamera(const vec3 position, const vec3 focalPoint, const vec3 up, const int level);
    
    int getLevel() const;
    void setLevel(const int level);
    
    virtual Bitmap render(const Scene & scene) const;
};

#endif
