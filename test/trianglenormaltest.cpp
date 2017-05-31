#include "scene/Scene.h"
#include "engine/PathTracer.h"
#include "camera/Camera.h"
#include "object/Triangle.h"
#include "light/PointLight.h"
#include "material/Lambert.h"
#include "image/Bitmap.h"

int main(int argc, char * argv[]) {
    
    Scene scn;
    PathTracer pt;
    scn.setRenderEngine(pt);
    scn.setBackgroundColor(Color(0.8, 0.9, 1.0));
    
    Lambert white = Lambert(Color(0.6, 0.6, 0.6));
    
    Vertex v0 = Vertex(vec3(-1, 0, 0));
    Vertex v1 = Vertex(vec3(1, 0, 0));
    Vertex v2 = Vertex(vec3(0, 1, 0));
    Triangle tri = Triangle(&v0, &v1, &v2);
    tri.setMaterial(white);
    scn.addObject(tri);
    
    PointLight redlgt = PointLight(Color::RED, vec3(0, 0, -1));
    PointLight greenlgt = PointLight(Color::GREEN, vec3(0, 0, 1));
    redlgt.setCastShadow(true);
    greenlgt.setCastShadow(true);
    scn.addLight(redlgt);
    scn.addLight(greenlgt);
    
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
    cam.lookAt(vec3(1, 1, 1), vec3(0, 0.3, 0));
    Image front = cam.render(scn);
    cout << endl << "Render Time Elapsed: " << time(0) - curr << "s" << endl;
    cam.lookAt(vec3(1, 1, -1), vec3(0, 0.3, 0));
    Image back = cam.render(scn);
    cout << endl << "Render Time Elapsed: " << time(0) - curr << "s" << endl;
    Bitmap::saveImage(front, "tri_front.bmp");
    Bitmap::saveImage(back, "tri_back.bmp");
    
    return 0;
}
