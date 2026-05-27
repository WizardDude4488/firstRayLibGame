#include <iostream>
#include <string.h>
#include "raylib.h"
#include <cstdio>



int main()
{
    InitWindow(640, 480, "Raze");


    SetTargetFPS(60);
    //SetWindowPosition(400, 400);

    //add the assets file directory to the project so we can use images, sounds, etc.
    //ChangeDirectory(TextFormat("%s/../assets/images", GetApplicationDirectory()));

    //check if window is being created
    if (IsWindowReady()) printf("Window is Ok\n");
    else printf("Window failed\n");


    //keep window open until user input tells game to close
    while (!WindowShouldClose()) {

        //printf("Loop iteration\n"); fflush(stdout);
        BeginDrawing();
        //printf("After begin drawing\n"); fflush(stdout);
            ClearBackground(BLACK);
            DrawText("It Works!", 24, 24, 20, WHITE);
        EndDrawing();
        //printf("After end drawing\n"); fflush(stdout);
    }

    CloseWindow();
    return 0;
}