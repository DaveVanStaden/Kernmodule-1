#ifndef SFML_CIRCLE_H
#define SFML_CIRCLE_H

#include <iostream>
#include "Vector2.h"

class Circle {
public:
    Circle(float xPos, float yPos, int windowWidth, int windowHeight);
    Circle() = default;
    float vSpeed;
    float hSpeed;
    float acceleration;
    float size;
    float force;
    float friction;
    Vector2 GetPosition();
    Vector2 Position;
    void UpdatePos(float newX, float newY);
};


#endif //SFML_CIRCLE_H
