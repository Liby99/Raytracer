#ifndef CAMERA_VIEWER_H
#define CAMERA_VIEWER_H

#include "scene/Scene.h"
#include "camera/Camera.h"

class CameraViewer : public Viewer {
private:
    
    Scene * scene;
    Camera * camera;
    
public:
    
    CameraViewer();
    CameraViewer(int width, int height);
    CameraViewer(int width, int height, Scene & scene, Camera & camera);
    
    void setScene(Scene & scene);
    void setCamera(Camera & camera);
};

#endif
