#include "scene/Scene.h"
#include "material/Diffuse.h"
#include "light/PointLight.h"
#include "light/DirectionalLight.h"
#include "object/Sphere.h"
#include "object/Plane.h"
#include "object/InstanceObject.h"
#include "camera/Camera.h"
#include "util/Bitmap.h"
#include "util/Color.h"
#include "util/Transform.h"

#include <iostream>
#include <glm/gtc/random.hpp>

using namespace std;

int main(int argc, char ** argv) {
    
    Scene scn;
    scn.setBackgroundColor(Color(0.8f, 0.8f, 1.0f));
    
    Diffuse diffuse = Diffuse(Color(1.0f, 1.0f, 1.0f));

    Plane ground;
    ground.addMaterial(diffuse);
    scn.addObject(ground);
    
    for (int i = 0; i < 20; i++) {
        float rad = glm::linearRand(0.25f, 0.5f);
        vec3 pos = vec3(glm::linearRand(-5.0f, 5.0f), rad, glm::linearRand(-5.0f, 5.0f));
        Sphere * sphere = new Sphere(rad);
        sphere->translate(pos);
        sphere->addMaterial(diffuse);
        scn.addObject(*sphere);
    }

    // Create lights
    DirectionalLight sunlgt;
    sunlgt.setColor(Color(1.0f, 1.0f, 0.9f));
    sunlgt.setIntensity(1.0f);
    sunlgt.setDirection(vec3(2.0f, -3.0f, -2.0f));
    sunlgt.setCastShadow(true);
    scn.addLight(sunlgt);

    // Create camera
    Camera cam;
    cam.lookAt(vec3(-0.75f, 0.25f, 5.0f), vec3(0.0f, 0.5f, 0.0f));
    cam.setFovy(40.0f);
    cam.setResolution(800, 600);
    
    cout << "Object: " << scn.objectAmount() << endl;

    // Render image
    Bitmap bmp = cam.render(scn);
    bmp.saveImage("final/project1ec.bmp");
    
    for (int i = 1; i < scn.objectAmount(); i++) {
        delete &(scn.getObject(i));
    }
}
