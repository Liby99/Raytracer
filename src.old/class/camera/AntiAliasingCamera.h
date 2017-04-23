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
    AntiAliasingCamera(int level);
    AntiAliasingCamera(vec3 position, vec3 focalPoint, int level);
    AntiAliasingCamera(vec3 position, vec3 focalPoint, vec3 up, int level);
    
    int getLevel() const;
    void setLevel(int level);
    
    virtual Bitmap render(const Scene & scene) const;
};

#endif
