#include <iostream>
#include <string>
#include "raylib.h"
#include "raymath.h"
#include <cstdio>


class Player
{
public:
    float pos_x;
    float pos_y;
    float speed = 200.0f;
    Vector2 position = {0, 0};
    Vector2 dir = {0,0};

    Player(float x, float y)
    {
        pos_x = x;
        pos_y = y;
        position = {pos_x, pos_y};


    }

    void update_pose()
    {
        //normalize with respect to a potentially variable frame rate
        float dt = GetFrameTime();
        //dir holds direction vector
        dir = {0};

        //components of dir modified by keyboard inputs
        if (IsKeyDown(KEY_D)) dir.x += 1.0f;
        if (IsKeyDown(KEY_A)) dir.x -= 1.0f;
        if (IsKeyDown(KEY_W)) dir.y -= 1.0f;
        if (IsKeyDown(KEY_S)) dir.y += 1.0f;

        //normalize the direction vector if there's input (avoids division by zero)
        if (Vector2Length(dir) > 0.0f)
            dir = Vector2Normalize(dir);

        //declare a new position based on adding the dir vector to old position
        position = Vector2Add(position, Vector2Scale(dir, (speed * dt)));

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

    //unlock and enable mouse for player direction control
    ShowCursor();
    EnableCursor();


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
            playerObj.update_pose();
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