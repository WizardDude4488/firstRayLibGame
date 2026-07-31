#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include "player.h"
#include "projectVariables.h"
#include "raylib.h"
#include "raymath.h"

//creating variables here for global functionality
float offsetX = 0;
float offsetY = 0;
float scale;

float Base_W = 1920;
float Base_H = 1080;

Camera2D playerCamera;

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
    //make sure to exactly match the case of the header file name
    player playerObj(Base_W/2, Base_H/2);
    playerCamera.offset = {Base_W/2, Base_H/2};
    playerCamera.target = playerObj.position;
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
            playerCamera.offset = {Base_W/2.0f, Base_H/2.0f};
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