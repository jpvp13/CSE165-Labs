#pragma once

#include <deque>
#include "RectChild.h"
#include "user.h"


class projectile{
    std::deque<RectChild*> bullet;
    std::deque<user*> ship;

public:
    projectile();

    void shoot();
};