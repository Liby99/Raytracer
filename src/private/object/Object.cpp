Object::DEFAULT_POSITION = vec3(0, 0, 0);
Object::DEFAULT_SCALER = vec3(1, 1, 1);
Object::DEFAULT_ROTATION = vec3(0, 0, 0);

mat4 Object::getTransformMatrix() {
    mat4 scale = Transform::scale(scaler.x, scaler.y, scaler.z);
    mat4 translate = Transform::translate(position.x, position.y, position.z);
    mat4 rotationX = Transform::rotate(vec3(1, 0, 0), rotation.x);
    mat4 rotationY = Transform::rotate(vec3(1, 0, 0), rotation.x);
    mat4 rotationZ = Transform::rotate(vec3(1, 0, 0), rotation.x);
    return translate * rotationZ * rotationY * rotationX * scale;
}

Object::Object() {
    rotate(DEFAULT_ROTATION);
    translate(DEFAULT_POSITION);
    scale(DEFAULT_SCALER);
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

void Object::scale(vec3 scaler) {
    this->scaler *= scaler;
}

void Object::scaleX(float scaleX) {
    scaler.x *= scaleX;
}

void Object::scaleY(float scaleY) {
    scale.y *= scaleY;
}

void Object::scaleZ(float scaleZ) {
    scale.z *= scaleZ;
}

void Object::intersect(Ray & ray) {
    return Intersection(ray, &this);
}
