#include "Paint.h"
#include <iostream>
#include <math.h>
#include "Button.h"
#include <deque>


#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

// std::deque<Button*> but;


Paint::Paint(){
    x = 0;
    y = 0;

    r = 0;
    g = 0;
    b = 0;

    choose = true;

    w = 0.2;
    h = 0.2;

    erase = false;
}



void Paint::draw(){
    //makes the points
    glColor3f(r, g, b);
    glPointSize(13);

    glBegin(GL_POINTS);

    glVertex2f(x, y);

    glEnd();
}


Paint::Paint(float x, float y, float w, float h, float r, float g, float b){

    this->x = x;
    this->y = y;

    this->r = r;
    this->g = g;
    this->b = b;

    this->w = w;
    this->h = h;

}