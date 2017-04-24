#include "scene/Scene.h"
#include "object/Plane.h"
#include "object/BoxTreeObject.h"
#include "object/InstanceObject.h"
#include "material/Diffuse.h"
#include "light/DirectionalLight.h"
#include "light/PointLight.h"
#include "camera/Camera.h"
#include "util/Bitmap.h"
#include "util/Color.h"

#include <iostream>

using namespace std;

int main() {
    
    // Create scene
    Scene scn;
    scn.setBackgroundColor(Color(0.8f, 0.8f, 1.0f));
    
    Diffuse diffuse = Diffuse();
    
    // Create ground
    Plane ground = Plane();
    ground.translateY(-0.1);
    ground.addMaterial(diffuse);
    scn.addObject(ground);
    
    // Create dragon
    BoxTreeObject dragon = BoxTreeObject();
    for (int i = 0; i < 10; i++) {
        dragon.addVertex(vec3(0, 0, -0.25 + i * 0.05));
        dragon.addVertex(vec3(0, 0.1, -0.25 + i * 0.05));
        dragon.addVertex(vec3(0.1, 0, -0.25 + i * 0.05));
        dragon.addTriangle(3 * i + 2, 3 * i + 1, 3 * i);
        if (i >= 1) dragon.addTriangle(3 * i, 3 * i + 1, 3 * i - 2);
    }
    dragon.addMaterial(diffuse);
    scn.addObject(dragon);
    
    // // Create instance
    // InstanceObject inst = InstanceObject(dragon);
    // inst.translate(vec3(-0.05f, 0.0f, -0.1f));
    // inst.rotateY(180);
    // inst.addMaterial(diffuse);
    // scn.addObject(inst);
    
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
    cam.lookAt(vec3(0.3f, 0.2f, 0.5f), vec3(0, 0, 0), vec3(0, 1.0f, 0));
    cam.setFovy(40.0f);
    cam.setResolution(800, 600);
    
    // Render image
    Bitmap bmp = cam.render(scn);
    bmp.saveImage("project2test1.bmp");
}
