#include <iostream>
#include <string>
#include "raylib.h"
#include "raymath.h"
#include <cstdio>
#include <algorithm>

//creating variables here for global functionality
float offsetX;
float offsetY;

float scale;

Camera2D playerCamera = {};

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
    Texture2D player = LoadTexture("images/players blue x3.png");
    Rectangle playerIdleSrc = {32,48,32,48};
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
        mouse = GetScreenToWorld2D(GetMousePosition(), playerCamera);

        //adjust mouse position based on the offset of the screen
        //do this after GetScreenToWorld2D since the window offsets are calculated last

        dst = {position.x, position.y, 32, 48};

        //update rotation of player based on updated mouse and dst
        mouseDir = Vector2Subtract(mouse, position);

        //calculate a new angle for the player rectangle to rotate to
        angle = atan2f(mouseDir.y, mouseDir.x) * RAD2DEG;
        std::cout << angle << std::endl;
        //std::cout << mouseDir.x << std::endl;
        //std::cout << mouseDir.y << std::endl;

        //draw player
        DrawTexturePro(player, playerIdleSrc, dst, origin, angle, WHITE);
    }

};

constexpr int Base_W = 1280;
constexpr int Base_H = 720;

int main()
{
    //make window resizable
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(Base_W, Base_H, "Raze");

    SetTargetFPS(60);

    //add the assets file directory to the project so we can use images, sounds, etc.
    ChangeDirectory(TextFormat("%s/../assets", GetApplicationDirectory()));
    Texture2D background = LoadTexture("images/john_xina.png");

    //player
    Player playerObj(Base_W/2, Base_H/2);
    playerCamera.zoom = 2.0f;

    Texture2D player = LoadTexture("players blue x3.png");

    //unlock and enable mouse for player direction control
    ShowCursor();
    EnableCursor();


    //check if window is being created
    if (IsWindowReady()) printf("Window is Ok\n");
    else printf("Window failed\n");

    //canvas
    RenderTexture2D canvas = LoadRenderTexture(Base_W, Base_H);
    SetTextureFilter(canvas.texture, TEXTURE_FILTER_TRILINEAR);

    //keep window open until user input tells game to close
    while (!WindowShouldClose()) {

        //Begin texture mode for drawing to canvas
        BeginTextureMode(canvas);
        //begin 2D mode with player camera,
        BeginMode2D(playerCamera);
            ClearBackground(BLACK);
            DrawTexture(background, 0, 0, WHITE);
            DrawText("It Works!", 24, 24, 20, WHITE);
            playerObj.update_pose();
            playerCamera.target = playerObj.position;
            playerCamera.offset = {Base_W/2, Base_H/2};
        EndMode2D();
        EndTextureMode();

        scale = std::min(
            (float)GetScreenWidth()/Base_W,
            (float)GetScreenHeight()/Base_H
        );

        offsetX = (GetScreenWidth() - Base_W * scale) * 0.5f;
        offsetY = (GetScreenHeight() - Base_H * scale) * 0.5f;

        Rectangle src = {0,0, (float)Base_W, -(float)Base_H};
        Rectangle dest = {offsetX, offsetY, (float)Base_W * scale, (float)Base_H * scale};

        //Drawing segment
        BeginDrawing();
            //clear previous frame
            ClearBackground(BLACK);
            //draw stuff on canvas to the window
            DrawTexturePro(canvas.texture, src, dest, {0,0}, 0.0f, WHITE);
        EndDrawing();

    }

    //add a for loop or a function to unload the textures
    UnloadTexture(background);
    UnloadTexture(player);
    UnloadRenderTexture(canvas);
    CloseWindow();
    return 0;
}