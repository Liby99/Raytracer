CameraViewer::CameraViewer(Camera & camera, Scene & scene) {
    
    // Setup the basic parameters
    this->camera = &camera;
    this->scene = &scene;
    
    int tmpc = 0;
    char * tmpv;
    
    //
    glutInit(&tmpc, &tmpv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(camera.getWidth(), camera.getHeight());
    
}
