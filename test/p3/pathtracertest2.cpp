#include "scene/Scene.h"
#include "camera/Camera.h"
#include "engine/RayTracer.h"
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
    PathTracer pathTracer = PathTracer(3);
    // RayTracer rayTracer;
    scn.setRenderEngine(pathTracer);
    scn.setBackgroundColor(Color(0.8f, 0.9f, 1.0f));
    
    Lambert white;
    Lambert green = Lambert(Color::GREEN);
    Lambert red = Lambert(Color::RED);

    // Create boxes
    Cube wall = Cube(5.0f, 5.0f, 0.1f);
    
    InstanceObject front = InstanceObject(wall);
    front.translateZ(-2.5f);
    front.setMaterial(white);
    
    InstanceObject back = InstanceObject(wall);
    back.translateZ(2.5f);
    back.setMaterial(white);
    
    InstanceObject left = InstanceObject(wall);
    left.rotateY(90);
    left.translateX(-2.5f);
    left.setMaterial(green);
    
    InstanceObject right = InstanceObject(wall);
    right.rotateY(90);
    right.translateX(2.5f);
    right.setMaterial(red);
    
    InstanceObject flr = InstanceObject(wall);
    flr.rotateX(90);
    flr.translateY(-2.5f);
    flr.setMaterial(white);
    
    InstanceObject cel = InstanceObject(wall);
    cel.rotateX(90);
    cel.translateY(2.5f);
    cel.setMaterial(white);
    
    scn.addObject(front);
    scn.addObject(left);
    scn.addObject(right);
    scn.addObject(back);
    scn.addObject(flr);
    scn.addObject(cel);

    PointLight lgt;
    lgt.setColor(Color::WHITE);
    lgt.setIntensity(5);
    lgt.setPosition(vec3(0, 2.3, 0));
    lgt.setCastShadow(true);
    scn.addLight(lgt);

    // Create camera
    Camera cam;
    cam.lookAt(vec3(0, 0, 2.3f), vec3(0.0f, 0.0f, 0.0f), vec3(0, 1, 0));
    cam.setResolution(720, 480);
    cam.setFovy(75.0f);
    
    cam.enableSampling();
    cam.setSamplingAmount(1);
    cam.setSamplingMethod(Sampler::UNIFORM_SAMPLE);
    cam.setWeightingMethod(Sampler::NO_WEIGHT);
    
    time_t curr = time(0);
    cam.onRender([curr](int i, int j, Color c, float progress) {
        int barWidth = 80;
        cout << "[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) std::cout << "=";
            else if (i == pos) std::cout << ">";
            else std::cout << " ";
        }
        cout << "] " << int(progress * 100.0) << "%, (" << time(0) - curr << "s)\r";
        cout.flush();
    });

    // Render image
    Image image = cam.render(scn);
    Bitmap::saveImage(image, "p3_test_2.bmp");
    
    cout << endl << "Total Time Elapsed: " << time(0) - curr << "s" << endl;
    return 0;
}
