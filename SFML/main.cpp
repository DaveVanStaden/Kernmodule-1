#include <iostream>
#include "Vector2.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

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


    Player player(windowWidth *0.4f,windowHeight-100,windowWidth,windowHeight);
    std::vector<Enemy> enemies;
    Enemy enemy(windowWidth *0.4f,0,windowWidth,windowHeight);
    for(int i = 0; i < 2;i++){
        enemies.push_back(Enemy(windowWidth *0.4f,0,windowWidth,windowHeight));
        currentEnemies +=1;
    }
    while(window->isOpen()){
        spawnTimer += 1;
        sf::Event event;
        enemy.Movement(windowWidth,windowHeight,window);
        for (auto &item : enemies) {
            item.Movement(windowWidth,windowHeight,window);
        }
        if (currentEnemies < maxEnemySpawn && spawnTimer >= enemySpawnRate){
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
                    if(event.key.code == sf::Keyboard::A){
                        player.MovementLeft();
                    }
                }
                if(player.Position.x <= windowWidth-100){
                    if(event.key.code == sf::Keyboard::D){
                        player.MovementRight();
                    }
                }
            }
            for(auto &item : enemies){
                if(player.CollidesWith(item)){
                    printf("IK STERF");
                }
            }
            if(player.CollidesWith(enemy)){
                //printf("IK STERF");
            }
        }
        window->clear();
        sf::CircleShape playerShape(50);
        enemy.DrawCircle(window);
        playerShape.setPosition(player.Position.x,player.Position.y);
        sf::FloatRect bounds = playerShape.getLocalBounds();
        sf::RectangleShape boundingBox(sf::Vector2f(bounds.width,bounds.height));
        boundingBox.setPosition(player.Position.x,player.Position.y);
        boundingBox.setFillColor(sf::Color::Red);
        window->draw(boundingBox);
        for (auto &item : enemies) {
            item.DrawCircle(window);
        }
        for(int i = 0; i < enemies.size(); i++){
            if(enemies[i].Position.y > windowHeight+100){
                enemies.erase(enemies.begin()+i);
                currentEnemies -= 1;
            }
        }
        window->draw(playerShape);
        window->display();
    }
    Vector2 v = Vector2();



}
