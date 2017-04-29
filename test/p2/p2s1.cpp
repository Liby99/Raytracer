#include "scene/Scene.h"
#include "object/Cube.h"
#include "object/BoxTreeObject.h"
#include "object/InstanceObject.h"
#include "material/Diffuse.h"
#include "light/DirectionalLight.h"
#include "light/PointLight.h"
#include "camera/Camera.h"
#include "util/Color.h"
#include "image/Bitmap.h"
#include "module/StopWatch.h"

#include <iostream>

using namespace std;

int main() {
    
    StopWatch watch;
    
    // Create scene
    Scene scn;
    scn.setBackgroundColor(Color(0.8f, 0.8f, 1.0f));
    
    Diffuse diffuse = Diffuse();
    
    // Create ground
    Cube ground = Cube(5, 0.1, 5);
    ground.addMaterial(diffuse);
    scn.addObject(ground);
    
    // Create dragon
    watch.start();
    cout << "Starting to build box tree" << endl;
    BoxTreeObject dragon = BoxTreeObject("res/dragon.ply");
    cout << "Completed building tree in " << watch.stop() << "s." << endl;
    dragon.addMaterial(diffuse);
    scn.addObject(dragon);
    
    // Create instance
    InstanceObject inst = InstanceObject(dragon);
    inst.translate(vec3(-0.05f, 0.0f, -0.1f));
    inst.rotateY(180);
    inst.addMaterial(diffuse);
    scn.addObject(inst);
    
    // Create lights
    DirectionalLight sunlgt = DirectionalLight(Color(1.0f, 1.0f, 0.9f), vec3(2.0f, -3.0f, -2.0f));
    sunlgt.setCastShadow(true);
    scn.addLight(sunlgt);
    
    PointLight redlgt = PointLight(Color(1.0f, 0.2f, 0.2f), vec3(-0.2f, 0.2f, 0.2f));
    redlgt.setIntensity(0.02f);
    redlgt.setCastShadow(true);
    scn.addLight(redlgt);
    
    PointLight bluelgt = PointLight(Color(0.2f, 0.2f, 1.0f), vec3(0.1f, 0.1f, 0.3f));
    bluelgt.setIntensity(0.02f);
    bluelgt.setCastShadow(true);
    scn.addLight(bluelgt);
    
    // Create camera
    Camera cam;
    cam.lookAt(vec3(-0.1f, 0.1f, 0.2f), vec3(-0.05f, 0.12f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
    cam.setFovy(40.0f);
    cam.setResolution(800, 600);
    
    cout << "Starting rendering process" << endl;
    watch.start();
    
    // Render image
    Image image = cam.render(scn);
    Bitmap::saveImage(image, "project2.bmp");
    
    cout << "Render Runtime: " << watch.stop() << "s" << endl;
}
 
