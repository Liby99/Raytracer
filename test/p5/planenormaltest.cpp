#include "scene/Scene.h"
#include "engine/PathTracer.h"
#include "camera/Camera.h"
#include "object/Plane.h"
#include "object/Cube.h"
#include "material/Luminance.h"
// #include "light/PointLight.h"
#include "material/Lambert.h"
#include "image/Bitmap.h"

int main(int argc, char * argv[]) {
    
    Scene scn;
    PathTracer pt;
    scn.setRenderEngine(pt);
    scn.setBackgroundColor(Color(0.8, 0.9, 1.0));
    
    Lambert white = Lambert(Color(0.6, 0.6, 0.6));
    Luminance red = Luminance(Color::RED);
    Luminance green = Luminance(Color::GREEN);
    
    Plane ground;
    ground.setMaterial(white);
    scn.addObject(ground);
    
    Cube c1 = Cube(0.5, 0.5, 0.5);
    c1.translateY(0.25);
    c1.setMaterial(red);
    scn.addObject(c1);
    
    Cube c2 = Cube(0.5, 0.5, 0.5);
    c2.translateY(-0.25);
    c2.setMaterial(green);
    scn.addObject(c2);
    
    // PointLight redlgt = PointLight(Color::RED, vec3(0, 1, 0));
    // PointLight greenlgt = PointLight(Color::GREEN, vec3(0, -1, 0));
    // redlgt.setCastShadow(true);
    // greenlgt.setCastShadow(true);
    // scn.addLight(redlgt);
    // scn.addLight(greenlgt);
    
    Camera cam;
    cam.setFovy(90.0f);
    cam.setResolution(800, 600);
    cam.enableSampling();
    cam.setSamplingAmount(4);
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
    cam.lookAt(vec3(0, 1, 2), vec3(0, 0, 0));
    Image front = cam.render(scn);
    cout << endl << "Render Time Elapsed: " << time(0) - curr << "s" << endl;
    cam.lookAt(vec3(0, -1, 2), vec3(0, 0, 0));
    Image back = cam.render(scn);
    cout << endl << "Render Time Elapsed: " << time(0) - curr << "s" << endl;
    Bitmap::saveImage(front, "plane_top.bmp");
    Bitmap::saveImage(back, "plane_bottom.bmp");
    
    return 0;
}
