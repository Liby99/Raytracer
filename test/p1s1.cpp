#include "scene/Scene.h"
#include "material/Diffuse.h"
#include "light/PointLight.h"
#include "light/DirectionalLight.h"
#include "object/MeshCube.h"
#include "object/InstanceObject.h"
#include "camera/Camera.h"
#include "util/Bitmap.h"
#include "util/Color.h"

#include <iostream>

using namespace std;

int main(int argc, char ** argv) {
    
    Scene scn;
    scn.setBackgroundColor(Color(0.8f, 0.9f, 1.0f));
    
    Diffuse diffuse = Diffuse(Color(1.0f, 1.0f, 1.0f));

    // Create boxes
    MeshCube box1 = MeshCube(5.0f,0.1f,5.0f);
    box1.addMaterial(diffuse);
    scn.addObject(box1);

    MeshCube box2 = MeshCube(1.0f,1.0f,1.0f);

    InstanceObject inst1(box2);
    inst1.rotateX(glm::degrees(0.5f));
    inst1.translateY(1);
    inst1.addMaterial(diffuse);
    scn.addObject(inst1);

    InstanceObject inst2(box2);
    inst2.rotateY(glm::degrees(1.0f));
    inst2.translate(vec3(-1, 0, 1));
    inst2.addMaterial(diffuse);
    scn.addObject(inst2);

    // Create lights
    DirectionalLight sunlgt;
    sunlgt.setColor(Color(1.0f, 1.0f, 0.9f));
    sunlgt.setIntensity(0.5f);
    sunlgt.setDirection(glm::vec3(-0.5f, -1.0f, -0.5f));
    scn.addLight(sunlgt);

    PointLight redlgt;
    redlgt.setColor(Color(1.0f, 0.2f, 0.2f));
    redlgt.setIntensity(2.0f);
    redlgt.setPosition(glm::vec3(2.0f, 2.0f, 0.0f));
    scn.addLight(redlgt);

    // Create camera
    Camera cam;
    cam.lookAt(glm::vec3(2.0f,2.0f,5.0f),glm::vec3(0.0f,0.0f,0.0f),glm::vec3(0,1,0));
    cam.setResolution(800,600);
    cam.setFovy(40.0f);

    // Render image
    Bitmap bmp = cam.render(scn);
    bmp.saveImage("final/project1.bmp");
}
