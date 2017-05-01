#include "viewer/Viewer.h"

void init() {
    
}

int main() {
    Viewer v = Viewer();
    v.init();
    v.setPixel(50, 50, Color(1, 0, 0));
    v.setPixel(100, 100, Color(0, 1, 0));
    v.setPixel(150, 100, Color(0, 0, 1));
}
