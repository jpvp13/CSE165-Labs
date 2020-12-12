#ifndef WINNER_H
#define WINNER_H

#include "Rect.h"
#include <vector>

// std::vector<Rect> box;
enum Thing {enu, EXX, OO};

struct Winner{
    // bool X;
    // bool O;

    Winner();
    Thing temp;

    bool Xwinner(std::vector<Rect> box);
    bool Owinner(std::vector<Rect> box);
};

#endif