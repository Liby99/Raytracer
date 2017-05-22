#include "scene/Scene.h"
#include ""

int main() {

    Scene scn;
    scn.setBackgroundColor(rgb(0.8f, 0.9f, 1.0f));
    
    // Materials
    const int nummtls=4;
    Ashikhmin mtl[nummtls];
    
    // Diffuse
    mtl[0].SetSpecularLevel(0.0f);
    mtl[0].SetDiffuseLevel(1.0f);
    mtl[0].SetDiffuseColor(Color(0.7f,0.7f,0.7f));
    
    // Roughened copper
    mtl[1].SetDiffuseLevel(0.0f);
    mtl[1].SetSpecularLevel(1.0f);
    mtl[1].SetSpecularColor(Color(0.9f,0.6f,0.5f));
    mtl[1].SetRoughness(100.0f,100.0f);
    
    // Anisotropic gold
    mtl[2].SetDiffuseLevel(0.0f);
    mtl[2].SetSpecularLevel(1.0f);
    mtl[2].SetSpecularColor(Color(0.95f,0.7f,0.3f));
    mtl[2].SetRoughness(1.0f,1000.0f);
    
    // Red plastic
    mtl[3].SetDiffuseColor(Color(1.0f,0.1f,0.1f));
    mtl[3].SetDiffuseLevel(0.8f);
    mtl[3].SetSpecularLevel(0.2f);
    mtl[3].SetSpecularColor(Color(1.0f,1.0f,1.0f));
    mtl[3].SetRoughness(1000.0f,1000.0f);
    
    // Load dragon mesh
    MeshObject dragon;
    dragon.LoadPLY("dragon.ply");
    
    // Create box tree
    BoxTreeObject tree;
    tree.Construct(dragon);
    
    // Create dragon instances
    glm::mat4 mtx;
    for(int i=0; i<nummtls; i++) {
        InstanceObject *inst=new InstanceObject(tree);
        mtx[3]=glm::vec4(0.0f,0.0f,-0.1f*float(i),1.0f);
        inst->SetMatrix(mtx);
        inst->SetMaterial(&mtl[i]);
        scn.AddObject(*inst);
    }
    
    // Create ground
    LambertMaterial lambert;
    lambert.SetDiffuseColor(Color(0.3f,0.3f,0.35f));
    MeshObject ground;
    ground.MakeBox(2.0f,0.11f,2.0f,&lambert);
    scn.AddObject(ground);
    
    // Create lights
    DirectLight sunlgt;
    sunlgt.SetBaseColor(Color(1.0f, 1.0f, 0.9f));
    sunlgt.SetIntensity(1.0f);
    sunlgt.SetDirection(glm::vec3 (2.0f, -3.0f, -2.0f));
    scn.AddLight(sunlgt);
    
    // Create camera
    Camera cam;
    cam.LookAt(glm::vec3(-0.5f,0.25f,-0.2f), glm::vec3(0.0f,0.15f,-0.15f));
    cam.SetFOV(40.0f);
    cam.SetAspect(1.33f);
    cam.SetResolution(800,600);
    cam.SetSuperSample(10,10);
    cam.SetJitter(true);
    cam.SetShirley(true);
    
    // Render image
    cam.Render(scn);
}
