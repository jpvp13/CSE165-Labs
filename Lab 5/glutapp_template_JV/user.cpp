//file will be used for both user and enemny ship as both have same attributes

#include <iostream>

#include "user.h"
// #include "RectChild.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


user::user(){
    ship.push_front(new RectChild(0.0, -0.6, 0.3, 0.2, 1, 1 ,1));
    enemy.push_front(new RectChild(-0.1, 0.6, 0.3, 0.2, 1, 0, 0));
    // bullet.push_front(new RectChild(0.0, 0.0, 0.2, 0.2, 0, 0 ,0));
}


void user::enemyDraw(){
    enemy[0]->newdraw();
}

void user::userDraw(){
    ship[0]->newdraw();
}

void user::moveUp(){  
    ship[0]->setY(ship[0]->getY() + 0.1);
}

void user::moveDown(){  
    ship[0]->setY(ship[0]->getY() - 0.1);
}

void user::moveLeft(){  
    ship[0]->setX(ship[0]->getX() - 0.1);
}

void user::moveRight(){  
    ship[0]->setX(ship[0]->getX() + 0.1);
}

void user::collision(){
    if((ship[0]->getY() >= enemy[0]->getY() - enemy[0]->getH()) && (ship[0]->getY() - ship[0]->getH() <= enemy[0]->getY() + 0.01)
        && (ship[0]->getX() <= enemy[0]->getX() + enemy[0]->getW()) && (ship[0]->getX() + ship[0]->getW() >= enemy[0]->getX() + 0.01)){
            std::cout << "Game Over!" << std::endl;
            exit(0);
        }
}


void user::shoot(){
    // bullet[0]->setX(ship[0]->getX() + ship[0]->getW()/2);
    // bullet[0]->setY(ship[0]->getY() + ship[0]->getH()/2);

    bullet[0]->newdraw();
}