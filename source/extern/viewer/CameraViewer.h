#ifndef CAMERA_VIEWER_H
#define CAMERA_VIEWER_H

#include <GLUT/glut.h>
#include <iostream>

#include "scene/Scene.h"
#include "camera/Camera.h"

class CameraViewer : public Viewer {
private:
    
    Scene * scene;
    Camera * camera;
    
public:
    
    CameraViewer(Camera & camera, Scene & scene);
};

#endif
