#include "scene/Scene.h"
#include "material/Ambient.h"
#include "material/Diffuse.h"
#include "light/PointLight.h"
#include "light/DirectionalLight.h"
#include "object/InstanceObject.h"
#include "object/Cube.h"
#include "object/Sphere.h"
#include "object/Plane.h"
#include "object/MeshCube.h"
#include "camera/Camera.h"
#include "util/Bitmap.h"
#include "util/Color.h"

#include <iostream>

using namespace std;

void printMat4(mat4 matrix) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char ** argv) {
    
    // Setup scene
    Scene scene;
    scene.setBackgroundColor(Color(0.8, 0.9, 1));
    
    Ambient ambient = Ambient(Color(0.1, 0.2, 0.3));
    Diffuse diffuse = Diffuse(Color(1, 1, 1));
    
    MeshCube cube = MeshCube(1, 1, 1);
    cube.addMaterial(ambient);
    cube.addMaterial(diffuse);
    scene.addObject(cube);
    
    InstanceObject box2 = InstanceObject(cube);
    box2.rotateX(45);
    box2.rotateY(45);
    box2.translateX(-1);
    box2.translateZ(1);
    box2.translateY(0.3);
    box2.addMaterial(ambient);
    box2.addMaterial(diffuse);
    scene.addObject(box2);
    
    cube.setWidth(1.5);
    
    Sphere sphere = Sphere(0.3);
    sphere.translateX(1);
    sphere.addMaterial(ambient);
    sphere.addMaterial(diffuse);
    scene.addObject(sphere);
    
    Plane plane = Plane(Plane::Y_POSITIVE);
    plane.addMaterial(ambient);
    plane.addMaterial(diffuse);
    plane.translateY(-0.5);
    scene.addObject(plane);
    
    PointLight point = PointLight(Color(1, 1, 1));
    point.setPosition(vec3(0, 0, 3));
    point.setFallOff(vec3(0, 0, 1));
    // point.setCastShadow(true);
    scene.addLight(point);
    
    Camera camera;
    camera.lookAt(vec3(2, 0.3, 2), vec3(0, 0, 0), vec3(0, 1, 0));
    camera.setResolution(240, 180);
    camera.setFovy(60);
    
    cout << "Starting to render" << endl;
    cout << scene.objectAmount() << " objects" << endl;
    cout << scene.lightAmount() << " lights" << endl;
    
    Bitmap bmp = camera.render(scene);
    bmp.saveImage("project1test10.png");
}
