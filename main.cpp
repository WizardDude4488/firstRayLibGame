#include <iostream>
#include <string.h>
#include "raylib.h"
using namespace std;

int screen_width = 1366;
int screen_height = 768;

class Player {
    public:
        void move() {
            int position_x = screen_width/2;
            int position_y = screen_height/2;
            if (IsKeyDown(KEY_RIGHT))
            {
                position_x += 5;
            } if (IsKeyDown(KEY_LEFT))
            {
                position_x -= 5;
            } if (IsKeyDown(KEY_UP))
            {
                position_y -= 5;
            } if (IsKeyDown(KEY_DOWN))
            {
                position_y += 5;
            }
        }
};


int main()
{
    //InitWindow function needs a constant character pointer to a title
    const char *title;
    title = "A";

    InitWindow(screen_width, screen_height, title);
    ClearBackground(WHITE);
    BeginDrawing();
    //BeginMode2D();

    Player playerObj;

    //keep window open until user input tells game to close
    while (WindowShouldClose() == false) {
        playerObj.move();
    }

}
