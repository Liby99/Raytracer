#ifndef BOUNDABLE_H
#define BOUNDABLE_H

class Boundable : public Object {
protected:
    
    // Virtual get bounding vertices method
    virtual vector<vec3> getBoundingVertices() const;
    
public:
    
    // Getting the bounding box
    BoundingBox getBoundingBox() const;
};

#endif
