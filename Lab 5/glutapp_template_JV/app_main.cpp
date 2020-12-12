#include "App.h"

int main(int argc, char** argv) {
    GlutApp* app = new App(argc, argv, 640, 640, "GLUT App");
                            //this is to change the size of the window

    app->run(); //only thing that should be on this file to make everything run
}
