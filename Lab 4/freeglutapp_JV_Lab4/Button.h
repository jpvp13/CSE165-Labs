#ifndef BUTTON_H
#define BUTTON_H

// #include "Paint.h"
#include <deque>


struct Button{

std::deque<Button*> boxx;

float x;
float y;
float w;
float h;

float r;
float g;
float b;

bool select;

bool erase;



Button();   //constructor

Button(float x, float y, float w, float h, float red, float green, float blue);


bool contains(float x, float y);



void box();


void draw();


bool selected();
bool deselected();
};


#endif