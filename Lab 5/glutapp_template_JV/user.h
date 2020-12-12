#ifndef SHIP_H
#define SHIP_H

#include <deque>
#include "RectChild.h"




class user{

   std::deque<RectChild*> ship;
   std::deque<RectChild*> enemy;
   std::deque<RectChild*> bullet;

public: 
    user();

    void userDraw();

    void enemyDraw();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void shoot();

    void collision();


};





#endif

