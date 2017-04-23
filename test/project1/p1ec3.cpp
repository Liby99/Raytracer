#include "scene/Scene.h"
#include "material/Diffuse.h"
#include "light/DirectionalLight.h"
#include "object/Sphere.h"
#include "object/Plane.h"
#include "object/GridCloner.h"
#include "camera/Camera.h"
#include "util/Bitmap.h"
#include "util/Color.h"
#include "util/Transform.h"

int main() {
    
    Scene scn;
    scn.setBackgroundColor(Color(0.8f, 0.8f, 1.0f));
    
    Diffuse diffuse = Diffuse(Color(1.0f, 1.0f, 1.0f));

    Plane ground;
    ground.addMaterial(diffuse);
    scn.addObject(ground);
    
    Sphere sphere = Sphere(0.5);
    sphere.translateY(0.25);
    
    GridCloner cloner = GridCloner(sphere);
    cloner.translateY(2);
    cloner.addMaterial(diffuse);
    scn.addObject(cloner);

    // Create lights
    DirectionalLight sunlgt;
    sunlgt.setColor(Color(1.0f, 1.0f, 0.9f));
    sunlgt.setIntensity(1.0f);
    sunlgt.setDirection(vec3(2.0f, -3.0f, -2.0f));
    sunlgt.setCastShadow(true);
    scn.addLight(sunlgt);

    // Create camera
    Camera cam;
    cam.lookAt(vec3(5.0f, 5.0f, 5.0f), vec3(0.0f, 0.5f, 0.0f));
    cam.setResolution(800, 600);
    cam.setFovy(40.0f);
    
    cout << "Object: " << scn.objectAmount() << endl;

    // Render image
    Bitmap bmp = cam.render(scn);
    bmp.saveImage("project1ec3.bmp");
}
