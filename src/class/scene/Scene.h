class Scene {
private:
    
    Color background;
    
    // Global Variables
    vector<Object *> objects;
    vector<Light *> lights;
    
public:
    
    // Constructor and Destructors
    Scene();
    
    Color getBackgroundColor();
    void setBackgroundColor(Color & color);
    
    //
    unsigned int lightAmount();
    Object & getLight(int i);
    void addLight(Light & light);
    
    //
    unsigned int objectAmount();
    Object & getObject(int i);
    void addObject(Object & object);
    
    
    // Intersection
    Intersection getIntersection(Ray & ray);
    Color getIntersectionColor(Intersection & intersection);
}
