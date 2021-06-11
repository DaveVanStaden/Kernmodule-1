#ifndef SFML_ENEMY_H
#define SFML_ENEMY_H
#define _DEBUG
#include "Circle.h"
#include <SFML/Graphics.hpp>

class Enemy : public Circle{
public:
    Enemy(float xPos, float yPos, int windowWidth, int windowHeight): Circle(xPos,yPos,windowWidth,windowHeight){};
    Enemy() = default;
    void Movement(int windowWidth, int windowHeight,sf::RenderWindow* RWindow);
    void DrawCircle(sf::RenderWindow* RWindow);
    void GenerateColor();
    void SetColor(int WhichColor, sf::CircleShape &circle);
    sf::CircleShape enemyShape;
    bool startDirection = false;
    int direction;
    int ballColor;

private:
};


#endif //SFML_ENEMY_H
