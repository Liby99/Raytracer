#include "scene/Scene.h"
#include "engine/PathTracer.h"
#include "material/Ashikhmin.h"
#include "material/Lambert.h"
#include "object/BoxTreeObject.h"
#include "object/InstanceObject.h"
#include "object/Cube.h"
#include "light/DirectionalLight.h"
#include "camera/Camera.h"
#include "image/Bitmap.h"

int BOUNCE = 10;
int SAMPLE = 4;

int main(int argc, char * argv[]) {
    
    int bounce = BOUNCE;
    int sample = SAMPLE;
    if (argc >= 2) {
        bounce = atoi(argv[1]);
    }
    if (argc >= 3) {
        sample = atoi(argv[2]);
    }
    
    Scene scn;
    PathTracer pt = PathTracer(bounce);
    scn.setRenderEngine(pt);
    scn.setBackgroundColor(rgb(0.8f, 0.9f, 1.0f));
    
    // Materials
    Ashikhmin mtl[4];
    InstanceObject * insts[4];
    Lambert lambert;
    lambert.setColor(Color(0.3f, 0.3f, 0.35f));
    
    // Diffuse
    mtl[0].setSpecularLevel(0.0f);
    mtl[0].setDiffuseLevel(1.0f);
    mtl[0].setDiffuseColor(Color(0.7f, 0.7f, 0.7f));
    
    // Roughened copper
    mtl[1].setDiffuseLevel(0.0f);
    mtl[1].setSpecularLevel(1.0f);
    mtl[1].setSpecularColor(Color(0.9f, 0.6f, 0.5f));
    mtl[1].setRoughness(100.0f, 100.0f);
    
    // Anisotropic gold
    mtl[2].setDiffuseLevel(0.0f);
    mtl[2].setSpecularLevel(1.0f);
    mtl[2].setSpecularColor(Color(0.95f, 0.7f, 0.3f));
    mtl[2].setRoughness(1.0f, 1000.0f);
    
    // Red plastic
    mtl[3].setDiffuseColor(Color(1.0f,0.1f,0.1f));
    mtl[3].setDiffuseLevel(0.8f);
    mtl[3].setSpecularLevel(0.2f);
    mtl[3].setSpecularColor(Color(1.0f,1.0f,1.0f));
    mtl[3].setRoughness(1000.0f, 1000.0f);
    
    // Create box tree
    BoxTreeObject dragon = BoxTreeObject("res/dragon.ply");
    
    // Create dragon instances
    for (int i = 0; i < 4; i++) {
        insts[i] = new InstanceObject(dragon);
        insts[i]->translateZ(-0.1f * float(i));
        insts[i]->setMaterial(mtl[i]);
        scn.addObject(*insts[i]);
    }
    
    // Create ground
    Cube ground = Cube(2.0f, 0.11f, 2.0f);
    ground.setMaterial(lambert);
    scn.addObject(ground);
    
    // Create lights
    DirectionalLight sunlgt = DirectionalLight(Color(1.0f, 1.0f, 0.9f), vec3(2.0f, -3.0f, -2.0f));
    sunlgt.setCastShadow(true);
    scn.addLight(sunlgt);
    
    // Create camera
    Camera cam;
    cam.lookAt(vec3(-0.5f, 0.25f, -0.2f), vec3(0.0f, 0.15f, -0.15f));
    cam.setFovy(40.0f);
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
    Bitmap::saveImage(image, "p4s1.bmp");
    
    cout << endl << "Render Time Elapsed: " << time(0) - curr << "s" << endl;
    
    // Delete all the dragons
    for (int i = 0; i < 4; i++) {
        delete insts[i];
    }
    
    return 0;
}
