#include "projectVariables.h"
#include "player.h"
#include <iostream>

/* (returntype) ClassName::MethodName(param1, param2, param3, etc.) { (implementation) }
*/
//when implementing methods, you must restate the method parameters and make sure the data types match
player::player(float x, float y)
{
    position = {x, y};
    collider(top_left, bottom_right);

    //add player rect to rect_list upon construction
    rect_list.push_back();
}


void player::update_pose()
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
        //mouse = mouse + GetMouseDelta();

        //first need to subtract the offsetx and offsety from the screen space coordinates
        //then, need to multiply by scaling factor which is based on the render dimensions, not screen dimensions
        //mouse.x = mouse.x - offsetX;
        //mouse.x = mouse.x * (Base_W/GetRenderWidth());
        //mouse.y = mouse.y - offsetY;
        //mouse.y = mouse.y * (Base_H/GetRenderHeight());

        //adjust mouse position based on the offset of the screen
        //do this after GetScreenToWorld2D since the window offsets are calculated last

        dst = {position.x, position.y, 32, 48};

        //calculate difference vector from player render position to mouse screen position
        screenPosition.x = float(GetScreenWidth())/2;
        screenPosition.y = float(GetScreenHeight())/2;
        mouseDir = Vector2Subtract(mouse, screenPosition);

        //calculate a new angle for the player rectangle to rotate to
        angle = atan2f(mouseDir.y, mouseDir.x) * RAD2DEG;
        std::cout << angle << std::endl;
        //std::cout << mouseDir.x << std::endl;
        //std::cout << mouseDir.y << std::endl;

        //draw player
        DrawTexturePro(playerTexture, playerIdleSrc, dst, origin, angle, WHITE);
}
