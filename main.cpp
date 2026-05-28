#include <iostream>
#include <string>
#include "raylib.h"
#include "raymath.h"
#include <cstdio>


class Player
{
public:
    float speed = 200.0f;
    Vector2 position = {0, 0};
    Vector2 dir = {0,0};
    Vector2 mouse = GetMousePosition();
    Vector2 origin = {16,24};
    Rectangle dst = {position.x,position.y, 32,48};
    Vector2 mouseDir = {0,0};
    float angle = 0;

    Player(float x, float y)
    {
        position = {x, y};

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

        //update mouse, rects, etc.
        mouse = GetMousePosition();
        dst = {position.x, position.y, 32, 48};

        //update rotation of player based on updated mouse and dst
        mouseDir = Vector2Subtract(mouse, position);

        //calculate a new angle for the player rectangle to rotate to
        angle = atan2f(mouseDir.y, mouseDir.x) * RAD2DEG;
        std::cout << angle << std::endl;
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
    Rectangle playerIdleSrc = {32,48,32,48};

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
            DrawTexturePro(player, playerIdleSrc, playerObj.dst, playerObj.origin, playerObj.angle, WHITE);
        EndDrawing();
        //printf("After end drawing\n"); fflush(stdout);
    }

    //add a for loop or a function to unload the textures
    UnloadTexture(background);
    CloseWindow();
    return 0;
}