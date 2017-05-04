#include "object/Object.h"

#include <iostream>

const vec3 Object::DEFAULT_POSITION = vec3(0, 0, 0);
const vec3 Object::DEFAULT_SCALER = vec3(1, 1, 1);
const vec3 Object::DEFAULT_ROTATION = vec3(0, 0, 0);

vec3 transfHomogenous(mat4 matrix, vec3 vertex) {
    vec4 v = matrix * vec4(vertex, 1);
    return vec3(v.x, v.y, v.z) / v.w;
}

bool Object::updateIntersect(Ray & ray, Intersection & intersection) {
    return false;
}

vector<vec3> Object::getBoundingVertices() {
    return vector<vec3>();
}

Object::Object() {
    setRotate(DEFAULT_ROTATION);
    setTranslate(DEFAULT_POSITION);
    setScale(DEFAULT_SCALER);
    transformed = false;
}

Material & Object::getMaterial() {
    return *material;
}

void Object::setMaterial(Material & material) {
    this->material = &material;
}

vec3 Object::getRotation() {
    return rotation;
}

vec3 Object::getScale() {
    return scaler;
}

vec3 Object::getPosition() {
    return position;
}

void Object::setRotate(vec3 rotation) {
    this->rotation = rotation;
    transformed = true;
}

void Object::rotate(vec3 rotation) {
    this->rotation += rotation;
    transformed = true;
}

void Object::rotateX(float degX) {
    rotation.x += degX;
    transformed = true;
}

void Object::rotateY(float degY) {
    rotation.y += degY;
    transformed = true;
}

void Object::rotateZ(float degZ) {
    rotation.z += degZ;
    transformed = true;
}

void Object::setTranslate(vec3 translate) {
    this->position = translate;
    transformed = true;
}

void Object::translate(vec3 translate) {
    this->position += translate;
    transformed = true;
}

void Object::translateX(float x) {
    position.x += x;
    transformed = true;
}

void Object::translateY(float y) {
    position.y += y;
    transformed = true;
}

void Object::translateZ(float z) {
    position.z += z;
    transformed = true;
}

void Object::setScale(vec3 scaler) {
    this->scaler = scaler;
    transformed = true;
}

void Object::scale(vec3 scaler) {
    this->scaler *= scaler;
    transformed = true;
}

void Object::scaleX(float scaleX) {
    scaler.x *= scaleX;
    transformed = true;
}

void Object::scaleY(float scaleY) {
    scaler.y *= scaleY;
    transformed = true;
}

void Object::scaleZ(float scaleZ) {
    scaler.z *= scaleZ;
    transformed = true;
}

mat4 Object::getTransformMatrix() {
    mat4 scale = Transform::scale(scaler.x, scaler.y, scaler.z);
    mat4 translate = Transform::translate(position.x, position.y, position.z);
    mat4 rotationX = Transform::rotate(rotation.x, vec3(1, 0, 0));
    mat4 rotationY = Transform::rotate(rotation.y, vec3(0, 1, 0));
    mat4 rotationZ = Transform::rotate(rotation.z, vec3(0, 0, 1));
    return translate * rotationZ * rotationY * rotationX * scale;
}

BoundingBox Object::getBoundingBox() {
    
    // Get all the vertices (approximatly 8) to find the bounding box
    vector<vec3> vertices = getBoundingVertices();
    
    BoundingBox box;
    
    // Check if the vector is empty
    if (vertices.empty()) {
        
        // If empty then return the empty box
        return box;
    }
    else {
        
        if (transformed) {
        
            // First cache the matrix
            mat4 m = getTransformMatrix();
            
            // Iterate through
            for (int i = 0; i < vertices.size(); i++) {
                
                // Transform and update min max
                vec3 v = transfHomogenous(m, vertices[i]);
                box.extend(v);
            }
        }
        else {
            
            // If not transformed then directly extend v
            for (int i = 0; i < vertices.size(); i++) {
                box.extend(vertices[i]);
            }
        }
        
        // Return the box
        return box;
    }
}

bool Object::intersect(Ray & ray, Intersection & intersection) {
    Ray transfRay = ray.inverseTransform(getTransformMatrix());
    if (updateIntersect(transfRay, intersection)) {
        intersection.transform(getTransformMatrix());
        intersection.setObject(*this);
        return true;
    }
    else {
        return false;
    }
}
