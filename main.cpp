#include <iostream>
#include <string>
#include "raylib.h"
#include <cstdio>


class Player
{
public:
    float pos_x;
    float pos_y;

    Player(float x, float y)
    {
        pos_x = x;
        pos_y = y;
    }

    void update_pos()
    {
        if (IsKeyPressed(KEY_RIGHT))
        {
            pos_x += 5;
        }
        if (IsKeyPressed(KEY_LEFT))
        {
            pos_x -= 5;
        }
        if (IsKeyPressed(KEY_UP))
        {
            pos_y -= 5;
        }
        if (IsKeyPressed(KEY_DOWN))
        {
            pos_y += 5;
        }
    }

};


int main()
{
    InitWindow(1366, 768, "Raze");


    SetTargetFPS(60);
    //SetWindowPosition(400, 400);

    //add the assets file directory to the project so we can use images, sounds, etc.

    ChangeDirectory(TextFormat("%s/../assets/images", GetApplicationDirectory()));
    Texture2D background = LoadTexture("john_xina.png");

    //player
    Player playerObj(100, 100);

    Texture2D player = LoadTexture("players blue x3.png");
    Rectangle playerIdleRect = {32,48,32,48};
    Vector2 playerIdlePos = {playerObj.pos_x, playerObj.pos_y};


    //check if window is being created
    if (IsWindowReady()) printf("Window is Ok\n");
    else printf("Window failed\n");


    //keep window open until user input tells game to close
    while (!WindowShouldClose()) {

        //printf("Loop iteration\n"); fflush(stdout);
        BeginDrawing();
        //printf("After begin drawing\n"); fflush(stdout);
            ClearBackground(BLACK);
            DrawTexture(background, 0, 0, WHITE);
            DrawText("It Works!", 24, 24, 20, WHITE);
            playerObj.update_pos();
            playerIdlePos = {playerObj.pos_x, playerObj.pos_y};
            DrawTextureRec(player, playerIdleRect, playerIdlePos, WHITE);
        EndDrawing();
        //printf("After end drawing\n"); fflush(stdout);
    }

    //add a for loop or a function to unload the textures
    UnloadTexture(background);
    CloseWindow();
    return 0;
}