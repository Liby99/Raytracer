#include "camera/Camera.h"

vec3 Camera::DEFAULT_POSITION = vec3(0, 0, 1);
vec3 Camera::DEFAULT_FOCAL_POINT = vec3(0, 0, 0);
vec3 Camera::DEFAULT_UP = vec3(0, 1, 0);
int Camera::DEFAULT_WIDTH = 720;
int Camera::DEFAULT_HEIGHT = 480;
float Camera::DEFAULT_FOVY = 90;

Camera::Camera() {
    lookAt(DEFAULT_POSITION, DEFAULT_FOCAL_POINT, DEFAULT_UP);
    setResolution(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    setFovy(DEFAULT_FOVY);
}

Camera::Camera(vec3 position, vec3 focalPoint) {
    lookAt(position, focalPoint, DEFAULT_UP);
    setResolution(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    setFovy(DEFAULT_FOVY);
}

Camera::Camera(vec3 position, vec3 focalPoint, vec3 up) {
    lookAt(position, focalPoint, up);
    setResolution(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    setFovy(DEFAULT_FOVY);
}

void Camera::lookAt(vec3 position, vec3 focalPoint) {
    setPosition(position);
    setFocalPoint(focalPoint);
    setUp(DEFAULT_UP);
}

void Camera::lookAt(vec3 position, vec3 focalPoint, vec3 up) {
    setPosition(position);
    setFocalPoint(focalPoint);
    setUp(up);
}

void Camera::setPosition(vec3 position) {
    this->position = position;
}

void Camera::setFocalPoint(vec3 focalPoint) {
    this->focalPoint = focalPoint;
}

void Camera::setUp(vec3 up) {
    this->up = up;
}

vec3 Camera::getPosition() {
    return position;
}

vec3 Camera::getFocalPoint() {
    return focalPoint;
}

vec3 Camera::getUp() {
    return up;
}

void Camera::setResolution(int width, int height) {
    setWidth(width);
    setHeight(height);
}

void Camera::setWidth(int width) {
    this->width = width;
}

void Camera::setHeight(int height) {
    this->height = height;
}

void Camera::setFovy(float fovy) {
    this->fovy = fovy;
}

Bitmap Camera::render(Scene & scene) {
    
    Bitmap bitmap(width, height);
    
    // Setup camera variables
    vec3 w = normalize(focalPoint - position);
    vec3 u = normalize(cross(w, up));
    vec3 v = cross(w, u);
    
    // Cached uniform variables
    float betaMult = -tan(glm::radians(fovy / 2));
    float alphaMult = betaMult * width / height;
    float halfWidth = width / 2.0f;
    float halfHeight = height / 2.0f;
    
    // Iterate through all the rays
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            
            // Then calculate alpha and beta then direction of ray
            float alpha = alphaMult * (halfWidth - i + 0.5f) / halfWidth;
            float beta = betaMult * (j - halfHeight + 0.5f) / halfHeight;
            vec3 dir = normalize(alpha * u + beta * v + w);
            
            Ray ray = Ray(position, dir);
            
            // Set the related pixel color
            bitmap.setPixel(i, j, scene.getRayColor(ray));
        }
    }
    
    // Return the bitmap
    return bitmap;
}
