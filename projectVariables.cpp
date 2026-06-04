#include "projectVariables.h"

//initialize variables in projectVariables.h to prevent issues in project
//need to specify type when initializing
Camera2D playerCamera = {};

//base screen dimensions
float Base_W = 1280;
float Base_H = 720;

//list of active rects
//putting {} at the end of an std::vector<_Ty> is the same as initializing it as empty
//thus, only put {} when initializing, not defining
std::vector<Rectangle> rect_list{};