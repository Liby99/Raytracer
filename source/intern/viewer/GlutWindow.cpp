#include "viewer/GlutWindow.h"

void GlutWindow::staticStart() {
    
    // Get the window
    GlutWindow * window = windows[activeWindow];
    glutSetWindow(activeWindow);
    
    // Initiate
    window->onInitListener();
    
    // Set event listeners
    glutDisplayFunc([] () {
        window->onDisplayListener();
    });
	// glutKeyboardFunc(window->onKeyboardListener);
    // glutMouseFunc(window->onMouseListener);
	// glutReshapeFunc(window->onResizeListener);
	// glutPassiveMotionFunc(window->onHoverListener);
	// glutMotionFunc(window->onDragListener);
    
    // Start Main Loop
    glutMainLoop();
}

GlutWindow::GlutWindow() : GlutWindow(DEFAULT_WIDTH, DEFAULT_HEIGHT) {}

GlutWindow::GlutWindow(int width, int height) : GlutWindow(width, height, "Glut Window") {}

GlutWindow::GlutWindow(int width, int height, const char * name) {
    
    setWidth(width);
    setHeight(height);
    
    int tmpc = 0;
    char * tmpv;
    
    glutInit(&tmpc, &tmpv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(width, height);
    
    currWindow = glutCreateWindow(name);
}
