#include "scene/Scene.h"
#include "camera/Camera.h"
#include "engine/PathTracer.h"
#include "material/Lambert.h"
#include "object/Cube.h"
#include "object/InstanceObject.h"
#include "object/BoxTreeObject.h"
#include "light/PointLight.h"
#include "image/Bitmap.h"

int SAMPLE = 64;
int BOUNCE = 10;

int main(int argc, char * argv[]) {
    
    int sample = SAMPLE;
    int bounce = BOUNCE;
    if (argc >= 2) {
        sample = atoi(argv[1]);
    }
    if (argc >= 3) {
        bounce = atoi(argv[2]);
    }
    
    Scene scn;
    PathTracer pt = PathTracer(bounce);
    scn.setRenderEngine(pt);
    scn.setBackgroundColor(Color::WHITE);
    
    Lambert white = Lambert(Color::WHITE);
    Lambert red = Lambert(Color::RED);
    Lambert green = Lambert(Color::GREEN);
    
    Cube wall = Cube(2, 0.05, 2);
    InstanceObject flr = InstanceObject(wall);
    InstanceObject cel = InstanceObject(wall);
    InstanceObject left = InstanceObject(wall);
    InstanceObject right = InstanceObject(wall);
    InstanceObject front = InstanceObject(wall);
    InstanceObject back = InstanceObject(wall);
    
    flr.setMaterial(white);
    
    cel.translateY(2);
    cel.setMaterial(white);
    
    left.rotateZ(90);
    left.translateY(1);
    left.translateX(-1);
    left.setMaterial(red);
    
    right.rotateZ(90);
    right.translateY(1);
    right.translateX(1);
    right.setMaterial(green);
    
    front.rotateX(90);
    front.translateZ(1);
    front.translateY(1);
    front.setMaterial(white);
    
    back.rotateX(90);
    back.translateZ(-1);
    back.translateY(1);
    back.setMaterial(white);
    
    scn.addObject(flr);
    scn.addObject(cel);
    scn.addObject(left);
    scn.addObject(right);
    scn.addObject(front);
    scn.addObject(back);
    
    BoxTreeObject dragon = BoxTreeObject("res/dragon.ply");
    dragon.scale(vec3(5, 5, 5));
    dragon.translateY(0.05);
    dragon.setMaterial(white);
    scn.addObject(dragon);
    
    // Cube lightCube = Cube(0.5, 0.01, 0.5);
    // AreaLight lgt = AreaLight(lightCube);
    PointLight lgt = PointLight(Color::WHITE, vec3(0, 1.9, 0));
    lgt.setCastShadow(true);
    // lgt.translateY(1.9);
    scn.addLight(lgt);
    
    Camera cam;
    cam.lookAt(vec3(-0.1, 0.9, 0.8), vec3(0, 0.8, 0));
    cam.setFovy(90.0f);
    cam.setResolution(800, 600);
    cam.enableSampling();
    cam.setSamplingAmount(sample);
    cam.setSamplingMethod(Sampler::JITTER_SAMPLE);
    cam.setWeightingMethod(Sampler::SHIRLEY_WEIGHT);
    
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
    Bitmap::saveImage(image, "cornell.bmp");
    
    cout << endl << "Render Time Elapsed: " << time(0) - curr << "s" << endl;
    
    return 0;
}
