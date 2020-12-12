#ifndef DRAG_H
#define DRAG_H

#include <deque>
#include "Rect.h"


struct drag{

    std::deque<Rect*> sqr;

    float x;
    float y;
    float w;
    float h;

    float Xdelta;
    float Ydelta;

  

    drag();

    void delta(float x, float y);

    void click(float x, float y);

    void motion(float x, float y);

    void square();
};


#endif