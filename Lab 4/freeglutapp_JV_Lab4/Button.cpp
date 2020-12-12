#include "Button.h"
#include "Paint.h"
#include <deque>


#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif



Button::Button(){

    x = 0;
    y = 0;

    w = 0.4;
    h = 0.4;

    r = 1;
    g = 0;
    b = 0;

    select = false;


}

Button::Button(float x, float y, float w, float h, float r, float g, float b){
	this->x = x;
	this->y = y;

	this->r = r;
	this->g = g;
	this->b = b;

	this->w = w;
	this->h = h;

	select = false;
	erase = false;
}

bool Button::selected(){
    select = true;
}

bool Button::deselected(){
    select = false;
}


// void Button::conditional(float x, float y, bool erase){
// 	for(std::deque<Button*>::iterator i = boxx.begin(); i != boxx.end(); i++){
// 		if (erase){
// 				(*i)->push_front(new Paint(x, y, 1, 1, 1));
// 		} else{
// 				(*i)->push_front(new Paint(x, y, 1, 0, 0));
// 			}
// 	}
// }




void Button::draw(){

	if(select){

		// ! this was found in lecture 6 timestamp 19:00
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);

	glVertex2f(x, y);
	glVertex2f(x+w, y);

	glVertex2f(x+w, y);
	glVertex2f(x+w, y-h);
	
	glVertex2f(x+w, y-h);
	glVertex2f(x, y-h);
	
	glVertex2f(x, y-h);
	glVertex2f(x, y);
	glEnd();

	} 


	glColor3f(r, g, b);
	glBegin(GL_POLYGON);

	glVertex2f(x, y);
	glVertex2f(x+w, y);

	glVertex2f(x+w, y);
	glVertex2f(x+w, y-h);
	
	glVertex2f(x+w, y-h);
	glVertex2f(x, y-h);
	
	glVertex2f(x, y-h);
	glVertex2f(x, y);
	glEnd();

}


bool Button::contains(float x, float y){
	return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}