#include "Enemy.h"
#include <iostream>
#include <SFML/Graphics.hpp>
void Enemy::Movement(int windowWidth, int windowHeight,sf::RenderWindow* RWindow){
    if(!startDirection){
        direction = (int) rand()%2;
        Position.x = rand()%windowWidth-150;
        Position.y = (rand()%300) -400;
        ballColor = rand() %3;
        startDirection = true;

    }
    if(speed <=0){
        speed = 0.1;
    }
    if(direction == 0){
        if(speed < maxSpeed && speed > minSpeed){
            speed += force;
        }
        Position.x -= speed;
        Position.y += 0.4f;
    }
    if(direction == 1){
        if(speed < maxSpeed && speed > minSpeed){
            speed += force;
        }
        Position.x += speed;
        Position.y += 0.4f;
    }
    if(Position.x <= 0){
        direction = 1;
        speed -= friction;
    }
    if(Position.x >= windowWidth - 150){
        direction = 0;
        speed -= friction;
    }
}

void Enemy::ResetPosition(){
    startDirection = false;

}
void Enemy::DrawCircle(sf::RenderWindow* RWindow) {
    SetColor(ballColor,enemyShape);
    enemyShape.setRadius(75);
    enemyShape.setPosition(Position.x,Position.y);
    RWindow->draw(enemyShape);
}

void Enemy::SetColor(int WhichColor, sf::CircleShape &circle){
    if(WhichColor == 0){
        circle.setFillColor(sf::Color::Green);
    }
    if(WhichColor == 1){
        circle.setFillColor(sf::Color::Red);
    }
    if(WhichColor == 2){
        circle.setFillColor(sf::Color::Blue);
    }
}