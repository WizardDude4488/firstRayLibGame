#include "collision.h"
#include <raylib.h>

collision::collision()
{
    Rectangle collision_rect;
}


//receiver receives and acts on collision information
//sender provides data relevant to collision and does not act on it in the context of the method call
std::vector<bool> collision::check_collision(Rectangle receiver, Rectangle sender)
{
    //create a collision rectangle for the overlap between the receiver and sender rectangles.
    collision_rect = GetCollisionRec(receiver, sender);

    //get the center of the collision rectangle
    Vector2 collision_center;
    collision_center.x = float(collision_rect.x + collision_rect.width/2);
    collision_center.y = float(collision_rect.y + collision_rect.height/2);

    Vector2 receiver_center;
    receiver_center.x = float(receiver.x + receiver.width/2);
    receiver_center.y = float(receiver.y + receiver.height/2);

    //subtract the receiver_center from the collision center
    Vector2 difference = Vector2Subtract(collision_center, receiver_center);

    //create booleans for collision sides
    bool collision_right = false;
    bool collision_left = false;
    bool collision_top = false;
    bool collision_bottom = false;

    //collision side logic
    if (difference.x > 0) collision_right = true;
    if (difference.x < 0) collision_left = true;
    if (difference.y < 0) collision_top = true;
    if (difference.y > 0) collision_bottom = true;

    //create return vector
    std::vector<bool> collision_sides{collision_right, collision_left,
    collision_top, collision_bottom};

    //return a boolean vector describing which sides of receiver are colliding
    return collision_sides;

}

void collision::collision_list()
{

}


