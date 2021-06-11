#include "Circle.h"
#include "Vector2.h"

Circle::Circle(float xPos, float yPos, int windowWidth, int windowHeight)
{
    Position.x = xPos;
    Position.y = yPos;
}

Vector2 Circle::GetPosition(){
    return Position;
}

void Circle::UpdatePos(float newX, float newY) {
    Position.x = newX;
    Position.y = newY;
}