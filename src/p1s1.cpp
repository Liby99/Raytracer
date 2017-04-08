#include "scene/Scene.h"
#include "material/Diffuse.h"
#include "light/PointLight.h"
#include "light/DirectionalLight.h"
#include "object/Cube.h"
#include "camera/Camera.h"
#include "util/Bitmap.h"
#include "util/Color.h"

int main(int argc, char ** argv) {
    
    // Setup scene
    Scene scene;
    scene.setBackgroundColor(Color(0.8, 0.9, 1));
    
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
    
    DirectionalLight sun = DirectionalLight(Color(1, 1, 0.9), vec3(-0.5, -1, -0.5));
    sun.setIntensity(0.5);
    
    PointLight point = PointLight(Color(1, 0.2, 0.2), vec3(2, 2, 0));
    point.setIntensity(0.5);
    
    Camera camera;
    camera.lookAt(vec3(3, 3, 3), vec3(0, 0, 0), vec3(0, 1, 0));
    camera.setSize(800, 600);
    camera.setFovy(90);
    
    Bitmap bmp = camera.render(scene);
    bmp.saveImage("project1.bmp");
}
