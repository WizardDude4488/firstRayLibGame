#pragma once
#include "projectVariables.h"
#include "collision.h"

class player
{
public:
    //initial values
    float speed = 200.0f;
    Vector2 position = {0, 0};
    Vector2 dir = {0,0};
    Vector2 mouse = GetMousePosition();
    Vector2 origin = {16,24};
    Rectangle dst = {position.x,position.y, 32,48};
    Vector2 mouseDir = {0,0};
    Texture2D playerTexture = LoadTexture("images/players blue x3.png");
    Rectangle playerIdleSrc = {32,48,32,48};
    float angle = 0;
    Vector2 screenPosition = {Base_W/2, Base_H/2};

    //rectangle for collision checking, etc.
    Rectangle rect;

    //make sure not to put curly braces for header file definition
    //curly braces basically tell the compiler to expect a definition
    //don't want to do that since these are defined elsewhere
    player(float x, float y);
    void update_pose();

    //initializing collider variables
    Vector2 top_left = {0,playerIdleSrc.height};
    Vector2 bottom_right = {playerIdleSrc.width, 0};

};
