#ifndef PAINTMAIN_H
#define PAINTMAIN_H

#include <deque>
#include "Paint.h"
#include "Button.h"

struct paintMain{
std::deque<Button*> lol;
std::deque<Paint*> brush;


float x;
float y;


float r;
float g;
float b;

float red;
float green;
float blue;



float w;
float h;
bool eraser;
bool color;

paintMain();

paintMain(float x, float y, float w, float h, float r, float g, float b);

void draw();
void point(float mx, float my);


};

#endif