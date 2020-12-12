#ifndef PAINT_H
#define PAINT_H

#include <deque>
#include "Button.h"



struct Paint{
	
	std::deque<Paint*> tool;
	// std::deque<Button*> button;


    float x;
	float y;

	float r;
	float g;
	float b;


	float w;
	float h;

	bool erase;
	bool leftclick;
	bool choose;


    Paint(); //constructor

	Paint(float x, float y, float w, float h, float r, float g, float b);



	// bool chose();
	// bool unchose();

	// void onClick(float x, float y, float r, float g, float b);
	// void conditional(float x, float y, bool erase);


	// void eraser(bool erase, float x, float y, float r, float g, float b);

	void draw();
	


};



#endif