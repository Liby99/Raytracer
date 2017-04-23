#include "object/Object.h"

vec3 Object::DEFAULT_POSITION = vec3(0, 0, 0);
vec3 Object::DEFAULT_SCALER = vec3(1, 1, 1);
vec3 Object::DEFAULT_ROTATION = vec3(0, 0, 0);

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
}

int Object::materialAmount() {
    return materials.size();
}

Material & Object::getMaterial(int i) {
    return *(materials[i]);
}

void Object::addMaterial(Material & material) {
    materials.push_back(&material);
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
}

void Object::rotate(vec3 rotation) {
    this->rotation += rotation;
}

void Object::rotateX(float degX) {
    rotation.x += degX;
}

void Object::rotateY(float degY) {
    rotation.y += degY;
}

void Object::rotateZ(float degZ) {
    rotation.z += degZ;
}

void Object::setTranslate(vec3 translate) {
    this->position = translate;
}

void Object::translate(vec3 translate) {
    this->position += translate;
}

void Object::translateX(float x) {
    position.x += x;
}

void Object::translateY(float y) {
    position.y += y;
}

void Object::translateZ(float z) {
    position.z += z;
}

void Object::setScale(vec3 scaler) {
    this->scaler = scaler;
}

void Object::scale(vec3 scaler) {
    this->scaler *= scaler;
}

void Object::scaleX(float scaleX) {
    scaler.x *= scaleX;
}

void Object::scaleY(float scaleY) {
    scaler.y *= scaleY;
}

void Object::scaleZ(float scaleZ) {
    scaler.z *= scaleZ;
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
    
    // Check if the vector is empty
    if (vertices.empty()) {
        
        // If empth then return the empty box
        return BoundingBox();
    }
    else {
        
        // First cache the matrix
        mat4 m = getTransformMatrix();
        
        // Calculate the first corner
        vec3 vertex = transfHomogenous(m, vertices[0]);
        vec3 minCorner = vertex;
        vec3 maxCorner = vertex;
        
        // Iterate through
        for (int i = 1; i < vertices.size(); i++) {
            
            // Transform and update min max
            vertex = transfHomogenous(m, vertices[i]);
            minCorner = minVec(minCorner, vertex);
            maxCorner = maxVec(maxCorner, vertex);
        }
        
        // Return the box
        return BoundingBox(minCorner, maxCorner);
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
