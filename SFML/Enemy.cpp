#include "Enemy.h"
#include <iostream>
#include <SFML/Graphics.hpp>
void Enemy::Movement(int windowWidth, int windowHeight,sf::RenderWindow* RWindow){
    if(!startDirection){
        direction = (int) rand()%2;
        Position.x = rand()%windowWidth-150;
        Position.y = (rand()%300) -400;
        //rand() %100;
        ballColor = rand() %3;
        startDirection = true;
        enemyShape.setRadius(75);
    }
    sf::Vector2i position = sf::Mouse::getPosition(*RWindow);
    Position.x = position.x;
    Position.y = position.y;
    /*if(direction == 0){
        Position.x -= 0.1f;
        Position.y += 0.05f;
    }
    if(direction == 1){
        Position.x += 0.1f;
        Position.y += 0.05f;
    }
    if(Position.x <= 0){
        direction = 1;
    }
    if(Position.x >= windowWidth - 150){
        direction = 0;
    }*/
}
void Enemy::DrawCircle(sf::RenderWindow* RWindow) {
    SetColor(ballColor,enemyShape);
    enemyShape.setPosition(Position.x,Position.y);
    sf::FloatRect bounds = enemyShape.getLocalBounds();
#ifdef _DEBUG
    sf::RectangleShape boundingBox(sf::Vector2f(bounds.width,bounds.height));
    boundingBox.setPosition(Position.x,Position.y);
    boundingBox.setFillColor(sf::Color::Red);
    RWindow->draw(boundingBox);
    #endif
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