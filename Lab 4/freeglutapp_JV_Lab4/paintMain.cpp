#include "paintMain.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

/*
THIS IS YOUR PAINT file

*/




paintMain::paintMain(){
    x = 0;
    y = 0;

    w = 0.2;
    h = 0.2;

    r = 0;
    g = 0;
    b = 0;

    red = 0;
    green = 0;
    blue = 0;


    
    eraser = false;
    color = false;


    lol.push_back(new Button(-0.56,-0.8, 0.3, 0.3, 0.5, 0.5, 0.5));  //this is black
    lol.push_back(new Button(-0.24,-0.8, 0.3, 0.3, 0.5, 0.5, 0.5));  //this is red
	lol.push_back(new Button(0.18, -0.8, 0.3, 0.3, 0.5, 0.5, 0.5)); //this is eraser
}

paintMain::paintMain(float x, float y, float w, float h, float r, float g, float b){
    this->x = 0;
    this->y = 0;

    this->w = 0.2;
    this->h = 0.2;

    this->r = 0;
    this->g = 0;
    this->b = 0;

    this->red = 0;
    this->green = 0;
    this->blue = 0;

  

    eraser = false;
    color = false;


}

void paintMain::draw(){

    for(int i = 0; i < brush.size(); i++){
		brush[i]->draw();
	}

    for(int k = 0; k < lol.size(); k++){
        lol[k]->draw();
    }
}


void paintMain::point(float mx, float my){
    for(std::deque<Button*>::iterator i = lol.begin(); i != lol.end(); i++){
        (*i)->deselected();
    }
    for(std::deque<Button*>::iterator i = lol.begin(); i != lol.end(); i++){
        if((*i)->contains(mx,my) && i == lol.begin() + 0 ){  //this is black
            (*i)->selected();
            color = true;
            eraser = false;
            red = 0;

        } else if((*i)->contains(mx,my) && i == lol.begin() + 1){   //this is red
            (*i)->selected();
            color = true;
            eraser = false;
            red = 1;

        } else if((*i)->contains(mx,my) && i == lol.begin() + 2){   //this is eraser
            (*i)->selected();
            color = false;
            eraser = true;
        }
    }

    if(color == true && red == 0){ //black
        brush.push_front(new Paint(mx, my , w, h, 0, 0 , 0));

    } else if(color == true && red == 1){
        brush.push_front(new Paint(mx, my , w, h, 1, 0 , 0));

    } else if(color == false && eraser == true){
        brush.push_front(new Paint(mx, my, w, h , 1, 1 , 1));
    }
    // } else if(color == true &&  red == 0 && green == 0 && blue == 0){
    //    brush.push_front(new Paint(mx, my, w, h , 1, 1, 1));
    // } 

    
}