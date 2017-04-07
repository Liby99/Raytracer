class Vertex {
private:
    vec3 position;
    vec3 normal;
public:
    
    //
    Vertex(vec3 position, vec3 normal);
    
    //
    vec3 getPosition();
    vec3 getNormal();
    
    //
    void setPosition(vec3 position);
    void setNormal(vec3 normal);
}
