#include <iostream>
#include "Vector2.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Score.h"
#include "Timer.h"
#include <windows.h>

int main() {
    std::cout << "Hello, World!" << std::endl;
    float windowWidth = 1280;
    float windowHeight = 680;
    float currentEnemies = 0;
    float maxEnemySpawn = 10;
    float spawnTimer = 0;
    float enemySpawnRate = 5000;
    srand((unsigned)time(0));
    sf::RenderWindow* window;
    window = new sf::RenderWindow (sf::VideoMode(windowWidth,windowHeight),"Window",sf::Style::Close | sf::Style::Titlebar);

    Score score;
    Timer gameTimer;
    Player player(windowWidth *0.4f,windowHeight-100,windowWidth,windowHeight);
    player.currForce = 0;
    std::vector<Enemy> enemies;
    for(int i = 0; i < 2;i++){
        enemies.push_back(Enemy(windowWidth *0.4f,0,windowWidth,windowHeight));
        currentEnemies +=1;
    }
    sf::Font font;
    if(!font.loadFromFile("Fonts/arial.ttf")){
        std::cout<<"error loading file " << std::endl;

        system("pause");
    }
    while(window->isOpen()){
        spawnTimer += 1;
        sf::Event event;
        if (!gameTimer.EndGame){
            for (auto &item : enemies) {
                item.Movement(windowWidth,windowHeight,window);
                item.force = 0.005;
                item.friction = 0.5;
            }
        }
        if (currentEnemies < maxEnemySpawn && spawnTimer >= enemySpawnRate && !gameTimer.EndGame){
            enemies.push_back(Enemy(windowWidth *0.4f,0,windowWidth,windowHeight));
            currentEnemies +=1;
            spawnTimer = 0;
        }
        while(window->pollEvent(event)){
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape){
                    window->close();
                }
                if(player.Position.x >= 0){
                    if(event.key.code == sf::Keyboard::A && !gameTimer.EndGame){
                        player.currForce = -0.25f;
                    }
                }
                if(player.Position.x <= windowWidth-100){
                    if(event.key.code == sf::Keyboard::D && !gameTimer.EndGame){
                        player.currForce = 0.25f;
                    }
                }
            }
            if (event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D){
                    player.currForce = 0;
                }
            }
        }
        if(player.Position.x > windowWidth-100)
            player.Position.x = windowWidth-100;
        if(player.Position.x <0)
            player.Position.x = 0;
        player.Movement(player.currForce);
        for(auto &item : enemies){
            if(player.collisionDetection(player.Position,item.Position,50,75)){
                item.ResetPosition();
                score.ScoreUp();
            }
        }
        window->clear();

        sf::CircleShape playerShape(50);
        playerShape.setPosition(player.Position.x,player.Position.y);
        for(auto &item : enemies) {
            if(item.Position.y > windowHeight+100){
                item.ResetPosition();
            }
        }
        for (auto &item : enemies) {
            item.DrawCircle(window);
        }
        if(gameTimer.EndGame){
            std::string scoreCountText(std::to_string(score.scoreCount));
            sf::Text scoreText("Congratulations on getting " + scoreCountText + "!",font);
            scoreText.setCharacterSize(40);
            scoreText.setFillColor(sf::Color::White);
            scoreText.setStyle(sf::Text::Bold);
            scoreText.setPosition((windowWidth/2)-400,(windowHeight/2)-100);
            window->draw((scoreText));
        }
        gameTimer.CountDown(window,font);
        score.DisplayScore(window,font);
        window->draw(playerShape);
        window->display();
    }
    Vector2 v = Vector2();



}
