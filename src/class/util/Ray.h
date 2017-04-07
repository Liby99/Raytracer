class Ray {
private:
    
    //
    vec3 origin;
    vec3 direction;
    int depth;
    bool insideFlag;
    
public:
    
    // Constructors
    Ray();
    Ray(vec3 origin, vec3 direction);
    Ray(vec3 origin, vec3 direction, int depth);
    
    // Setter
    void setOrigin(vec3 origin);
    void setDirection(vec3 direction);
    
    // Getter
    vec3 getOrigin();
    vec3 getDirection();
    
    // Inside or Outside Getter Setter
    void setInside();
    void setOutside();
    bool inside();
    
    // Transform
    Ray inverseTransform(mat4 transf);
}
