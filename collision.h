#pragma once
#include <raylib.h>
#include <vector>
#include <raymath.h>
#include "projectVariables.h"

//define a struct for a generalized collider

struct collider
{
    float left_x;
    float right_x;
    float top_y;
    float bottom_y;

    collider (Vector2 top_left, Vector2 bottom_right)
    {
        left_x = top_left.x;
        top_y = top_left.y;
        right_x = bottom_right.x;
        bottom_y = bottom_right.y;
    }
};

class collision {
    collision();
    std::vector<bool> check_collision(Rectangle object1, Rectangle object2);
};
