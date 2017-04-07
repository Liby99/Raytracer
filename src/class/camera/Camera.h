#ifndef CAMERA_H
#define CAMERA_H

class Camera {
private:
    
    // Constants
    const static vec3 DEFAULT_POSITION;
    const static vec3 DEFAULT_FOCUS;
    const static vec3 UP;
    
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
    Camera(vec3 position, vec3 focalPoint, vec3 up);
    
    void lookAt(vec3 position, vec3 focalPoint, vec3 up);
    
    void setPosition(vec3 position);
    void setFocalPoint(vec3 focalPoint);
    void setUp(vec3 up);
    
    vec3 getPosition();
    vec3 getFocalPoint();
    vec3 getUp();
    
    void setSize(int width, int height);
    void setWidth(int width);
    void setHeight(int height);
    
    // Render Functions
    Bitmap render(const Scene & scene);
};

#endif
