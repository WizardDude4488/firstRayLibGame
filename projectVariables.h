#pragma once
#include <raylib.h>
#include <raymath.h>
#include "collision.h"
#include "cmath"
#include "vector"

//create variables for the screen dimensions
extern float Base_W;
extern float Base_H;

//create player camera
extern Camera2D playerCamera;

//create a rect array to keep track of all entities
extern std::vector<Rectangle> rect_list;