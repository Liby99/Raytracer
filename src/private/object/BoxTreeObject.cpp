BoxTreeNode::BoxTreeNode(Triangle * tri) {
    box = BoundingBox(tri);
    triangles.push_back(tri);
    leafFlag = true;
}

BoxTreeNode::BoxTreeNode(vector<Triangle *> & tris) {
    int n = tris.size();
    
    // Construct Bounding Box
    box = BoundingBox(tris);
    vec3 size = box.getSize();
    int axis = maxAxis(size);
    float mid = box.getMinCorner()[axis] + size[axis] / 2;
    
    //
    if (n == 0) {
        leafFlag = false;
        return;
    }
    else if (n == 1) {
        leafFlag = true;
        triangles.push_back(tris[0]);
    }
    else if (n == 2) {
        left = new BoxTreeNode(tris[0]);
        right = new BoxTreeNode(tris[1]);
    }
    else {
        vector<Triangle *> leftTris;
        vector<Triangle *> rightTris;
        for (int i = 0; i < n; i++) {
            if (tris[i]->getCenter()[axis] < mid) {
                leftTris.push_back(tris[i]);
            }
            else {
                rightTris.push_back(tris[i]);
            }
        }
        if (leftTris.size() == tris.size() || rightTris.size() == tris.size()) {
            triangles = tris;
            leafFlag = true;
        }
        else {
            left = new BoxTreeNode(leftTris);
            right = new BoxTreeNode(rightTris);
            box = BoundingBox.combine(left.getBoundingBox(), right.getBoundingBox());
            leafFlag = false;
        }
    }
}

BoxTreeNode::~BoxTreeNode() {
    if (left) {
        delete left;
    }
    if (right) {
        delete right;
    }
}

BoxTreeNode & BoxTreeNode::getLeft() {
    return *left;
}

BoxTreeNode & BoxTreeNode::getRight() {
    return *right;
}

BoundingBox & BoxTreeNode::getBoundingBox() {
    return box;
}

bool BoxTreeNode::leftRightIntersect() {
    if (isLeaf()) {
        return false;
    }
    return left.getBoundingBox().intersect(right.getBoundingBox());
}

bool BoxTreeNode::isLeaf() {
    return leafFlag;
}

bool BoxTreeNode::intersect(Ray & ray, Intersection & intersection) {
    
    bool hit = false;
    
    if (isLeaf()) {
        
        for (int i = 0; i < triangles.size(); i++) {
            if (triangles[i]->intersect(ray, intersection)) {
                hit = true;
            }
        }
        return hit;
    }
    else {
        
        // Prepare all the variables
        BoundingBox & b1 = left.getBoundingBox(),
                      b2 = right.getBoundingBox();
        float t1, t2;
        bool i1, i2;
        i1 = b1.intersect(ray, t1);
        i2 = b2.intersect(ray, t2);
        
        // Check intersection
        if (i1 && i2) {
            if (leftRightIntersect()) {
                if (left.intersection(ray, intersection)) {
                    hit = true;
                }
                if (right.intersection(ray, intersection)) {
                    hit = true;
                }
            }
            else {
                if (t1 < t2) {
                    if (!left.intersect(ray, intersection)) {
                        if (right.intersect(ray, intersection)) {
                            hit = true;
                        }
                    }
                    else {
                        hit = true;
                    }
                }
                else {
                    if (!right.intersect(ray, intersection)) {
                        if (left.intersect(ray, intersection)) {
                            hit = true;
                        }
                    }
                    else {
                        hit = true;
                    }
                }
            }
            return flag;
        }
        else if (i1) {
            return left.intersect(ray, intersection);
        }
        else if (i2) {
            return right.intersect(ray, intersection);
        }
        else {
            return false;
        }
    }
}

void BoxTreeObject::clearTree() {
    
}

void BoxTreeObject::forceConstruct() {
    
}

void BoxTreeObject::constructTree() {
    if (!root) {
        root = BoxTreeNode(triangles);
    }
}

bool BoxTreeObject::updateIntersect(Ray & ray, Intersection & intersection) {
    constructTree()
    if (root.intersect(ray, intersection)) {
        intersection.setObject(*this);
        return true;
    }
    return false;
}

BoxTreeObject::BoxTreeObject() : MeshObject() {}

BoxTreeObject::BoxTreeObject(char * filename) : MeshObject(filename) {}

BoxTreeObject::~BoxTreeObject() : ~MeshObject() {
    delete root;
}
