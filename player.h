#pragma once
#include "projectVariables.h"

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


    player() {}

    void update_pose() {}

};
