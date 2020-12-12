#include <iostream>
#include "App.h"


#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    game = new Game();

}

void App::draw() {
    game->drawgame();
    
}

void App::keyDown(unsigned char key, float x, float y){
 
    if (key == 27){
        exit(0);
    }
    game->handles(key);
    
}


App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete game;
}
