class Object {
private:
    
    // Materials
    vector<Material *> materials;
    
    // Transform properties
    vec3 position;
    vec3 scale;
    vec3 rotation;
    
    // Get transformation helper method
    mat4 getTransformation();
    
public:
    
    // Constructor
    Object();
    
    // Material Related
    int materialAmount();
    Material & getMaterial(int i);
    void addMaterial(Material * material);
    
    // Overall Transformation
    void setTransform(mat4 matrix);
    
    // Rotate Transformation
    void rotateX(float degX);
    void rotateY(float degY);
    void rotateZ(float degZ);
    
    // Translate Transformation
    void translate(vec3 position);
    void translateX(float x);
    void translateY(float y);
    void translateZ(float z);
    
    // Scale Transformation
    void scale(vec3 scale);
    void scaleX(vec3 scaleX);
    void scaleY(vec3 scaleY);
    void scaleZ(vec3 scaleZ);
}
