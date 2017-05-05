#include "scene/Scene.h"
#include "camera/Camera.h"
#include "engine/PathTracer.h"
#include "material/Lambert.h"
#include "object/Cube.h"
#include "object/InstanceObject.h"
#include "light/PointLight.h"
#include "light/DirectionalLight.h"
#include "object/Plane.h"
#include "image/Bitmap.h"

int main() {
    
    Scene scn;
    PathTracer pathTracer;
    scn.setRenderEngine(pathTracer);
    scn.setBackgroundColor(Color(0.8f, 0.9f, 1.0f));
    
    Lambert lambert;

    // Create boxes
    Cube box1 = Cube(5.0f,0.1f,5.0f);
    box1.setMaterial(lambert);
    scn.addObject(box1);

    Cube box2 = Cube(1.0f,1.0f,1.0f);

    InstanceObject inst1(box2);
    inst1.rotateX(glm::degrees(0.5f));
    inst1.translateY(1);
    inst1.setMaterial(lambert);
    scn.addObject(inst1);

    InstanceObject inst2(box2);
    inst2.rotateY(glm::degrees(1.0f));
    inst2.translate(vec3(-1, 0, 1));
    inst2.setMaterial(lambert);
    scn.addObject(inst2);

    // Create lights
    DirectionalLight sunlgt;
    sunlgt.setColor(Color(1.0f, 1.0f, 0.9f));
    sunlgt.setIntensity(1.0f);
    sunlgt.setDirection(glm::vec3(-0.5f, -1.0f, -0.5f));
    sunlgt.setCastShadow(true);
    scn.addLight(sunlgt);

    PointLight redlgt;
    redlgt.setColor(Color(1.0f, 0.2f, 0.2f));
    redlgt.setIntensity(4.0f);
    redlgt.setPosition(glm::vec3(2.0f, 2.0f, 0.0f));
    redlgt.setCastShadow(true);
    scn.addLight(redlgt);

    // Create camera
    Camera cam;
    cam.lookAt(glm::vec3(2.0f,2.0f,5.0f),glm::vec3(0.0f,0.0f,0.0f),glm::vec3(0,1,0));
    cam.setResolution(800,600);
    cam.setFovy(40.0f);
    
    cam.enableSampling();
    cam.setSamplingAmount(9);
    cam.setSamplingMethod(Sampler::JITTER_SAMPLE);
    cam.setWeightingMethod(Sampler::SHIRLEY_WEIGHT);

    // Render image
    Image image = cam.render(scn);
    Bitmap::saveImage(image, "project1scene1_pathtrace.bmp");
}
