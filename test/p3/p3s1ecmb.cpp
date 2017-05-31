#include "camera/Camera.h"
#include "engine/PathTracer.h"
#include "scene/Scene.h"
#include "util/Sampler.h"
#include "object/Cube.h"
#include "object/InstanceObject.h"
#include "object/BoxTreeObject.h"
#include "material/Lambert.h"
#include "material/Metal.h"
#include "light/DirectionalLight.h"
#include "image/Bitmap.h"

int BOUNCE = 10;
int SAMPLE_AMOUNT = 100;

int main() {
    
    Scene scn;
    PathTracer pt = PathTracer(BOUNCE);
    scn.setRenderEngine(pt);
    
    scn.setBackgroundColor(Color(0.8, 0.9, 1.0));
    
    Lambert groundMtl = Lambert(Color(0.25f, 0.25f, 0.25f));
    Lambert white = Lambert(Color(0.7f, 0.7f, 0.7f));
    Lambert red = Lambert(Color(0.7f, 0.1f, 0.1f));
    Metal metal = Metal(Color(0.95f, 0.64f, 0.54f));
    
    Cube ground = Cube(2, 0.11, 2);
    ground.setMaterial(groundMtl);
    scn.addObject(ground);
    
    BoxTreeObject dragon = BoxTreeObject("res/dragon.ply");
    
    InstanceObject * insts[4];
    Material * mtls[4] = {&white, &metal, &red, &white};
    for (int i = 0; i < 4; i++) {
        insts[i] = new InstanceObject(dragon);
        insts[i]->translateZ(0.3f * (float(i) / float(3) - 0.5f));
        insts[i]->setMaterial(*mtls[i]);
        
        // Animation
        insts[i]->translateX(-(i / 8.0f), 0);
        insts[i]->translateX(i / 4.0f, 1);
        // Animation
        
        scn.addObject(*insts[i]);
    }
    
    DirectionalLight sunlgt = DirectionalLight(Color(1.0f, 1.0f, 0.9f), vec3(2.0f, -3.0f, -2.0f));
    sunlgt.setCastShadow(true);
    scn.addLight(sunlgt);
    
    Camera cam;
    cam.setResolution(640, 480);
    cam.lookAt(vec3(-0.5f, 0.25f, -0.2f), vec3(0.0f, 0.15f, 0.0f));
    cam.setFovy(40.0f);
    cam.enableSampling();
    cam.setSamplingAmount(SAMPLE_AMOUNT);
    cam.setSamplingMethod(Sampler::JITTER_SAMPLE);
    cam.setWeightingMethod(Sampler::SHIRLEY_WEIGHT);
    
    cam.enableMotionBlur();
    cam.setShutterSpeed(0.2);
    
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
    Image image = cam.render(scn, 0.4);
    Bitmap::saveImage(image, "p3s1_ec_mb.bmp");
    
    cout << endl << "Render Time Elapsed: " << time(0) - curr << "s" << endl;
    
    // Delete all the dragons
    for (int i = 0; i < 4; i++) {
        delete insts[i];
    }
    
    return 0;
}
