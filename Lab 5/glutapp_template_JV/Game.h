#ifndef GAME_h
#define GAME_h

#include "user.h"
// #include "enemy.h"
#include "projectile.h"


#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


struct Game{

    user ship;
    projectile projectile;

public:
    bool fired;
    Game();

    void drawgame();
    void drawshot();

    void up();
    void down();
    void left();
    void right();

    void handles(unsigned char);

};



#endif