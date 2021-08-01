#ifndef SFML_PLAYER_H
#define SFML_PLAYER_H

#include "Circle.h"
#include "Enemy.h"

class Player : public Circle {
public:
    Player(float xPos, float yPos, int windowWidth, int windowHeight): Circle(xPos,yPos,windowWidth,windowHeight){};
    Player() = default;
    void Movement(float force);
    float minSpeed = -5;
    float speed = 1;
    float maxSpeed = 5;
    float currForce = 0;
private:
};


#endif //SFML_PLAYER_H
