#ifndef SFML_PLAYER_H
#define SFML_PLAYER_H

#include "Circle.h"
#include "Enemy.h"

class Player : public Circle {
public:
    Player(float xPos, float yPos, int windowWidth, int windowHeight): Circle(xPos,yPos,windowWidth,windowHeight){};
    Player() = default;
    void MovementLeft();
    void MovementRight();
    bool CollidesWith(Enemy& e);
private:
};


#endif //SFML_PLAYER_H
