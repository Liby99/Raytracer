class Color {
private:
    float r;
    float g;
    float b;
public:
    
    // Constructors
    Color();
    Color(float r, float g, float b);
    
    // Getters
    float getR();
    float getG();
    float getB();
    
    // To int version
    int getIntR();
    int getIntG();
    int getIntB();
    
    // Setters
    void setR(float r);
    void setG(float g);
    void setB(float b);
    
    // Operators
    Color operator+(Color c);
    Color operator-(Color c);
    Color operator*(Color c);
    Color operator*(float scale);
}
