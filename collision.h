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

//define a list of active rects for collision checking
extern std::vector<bool> collider_list{};


class collision {
public:
    collision();
    std::vector<bool> check_collision(Rectangle receiver, Rectangle sender);

    //define a method for checking through a list of active collision rects
    //should return the name of each rect and the collision list
    //for example, "player: {collision_right, collision_top}"

    void check_collision_list(std::vector<bool> collider_list);
private:
    Rectangle collision_rect;
};
