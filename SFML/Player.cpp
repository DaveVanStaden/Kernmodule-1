#include "Player.h"
#include <iostream>
void Player::Movement(float force){
    if(speed < maxSpeed && speed > minSpeed){
        speed += force;
    }

    if(speed > 0){
        speed -= friction;
    }
    else if (speed < 0){
        speed += friction;
    }

    Position.x += speed;
}
