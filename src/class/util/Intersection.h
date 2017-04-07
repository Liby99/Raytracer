class Intersection {
private:
    Ray & ray;
    Object & object;
    bool hitFlag;
    float t;
    vec3 position;
    vec3 normal;
    
public:
    Intersection();
}
