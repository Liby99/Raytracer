int main(int argc, char ** argv) {
    
    // Setup scene
    Scene scene;
    scene.setBackgroundColor(Color(0.5, 0.5, 0.5));
    
    // Setup basic material
    Diffuse diffuse = Diffuse(Color(1, 1, 1));
    
    Cube box1 = Cube(1, 1, 1);
    box1.rotateX(45);
    box1.translateX(-1);
    box1.addMaterial(diffuse);
    scene.addObject(box1);
    
    Cube box2 = Cube(1, 1, 1);
    box2.translateZ(1);
    box2.addMaterial(diffuse);
    scene.addObject(box2);
    
    Cube floor = Cube(10, 10, 0.1);
    floor.translateY(-0.5);
    scene.addObject(floor);
    
    Camera camera;
    camera.lookAt(vec3(3, 3, 3), vec3(0, 0, 0), vec3(0, 1, 0));
    
    Bitmap bmp = camera.render(scene);
    bmp.sameImage("project1.bmp");
}
