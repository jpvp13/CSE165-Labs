#include <iostream>
#include "Game.h"

Game::Game(){
}


void Game::drawgame(){
    ship.userDraw();
    ship.enemyDraw();
}


void Game::drawshot(){
    // fired = true;
    projectile.shoot();
}

void Game::handles(unsigned char key ){
    if( key == 'w'){
        ship.moveUp();
    std::cout << "hello" << std::endl;
        // 0
    } else if( key == 'a'){
        ship.moveLeft();
        
        // std::cout << "Left was clicked inside of App.cpp!" << std::endl;
    } else if( key == 'd'){
        ship.moveRight();
      
        // std::cout << "Right was clicked inside of App.cpp!" << std::endl;
    } else if( key == 's'){
        ship.moveDown();
        
        // std::cout << "Down was clicked inside of App.cpp!" << std::endl;
    } else if (key == ' '){
        ship.shoot();
   
        // std::cout << "Space was clicked inside of App.cpp!" << std::endl;
    } 

    // ship.collision();

}


//THIS WAS WORKING :(