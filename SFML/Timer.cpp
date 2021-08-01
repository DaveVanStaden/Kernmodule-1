//
// Created by davev on 1-8-2021.
//

#include "Timer.h"
#include <SFML/Graphics.hpp>
#include <iostream>
void Timer::CountDown(sf::RenderWindow* RWindow, sf::Font font) {
    if(time > 0){
        time -=0.003;
    } else{
        EndGame = true;
    }
    std::string TimeString(std::to_string(time));
    sf::Text scoreText("Current time: " + TimeString,font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setStyle(sf::Text::Bold);
    scoreText.setPosition(0,40);
    RWindow->draw((scoreText));
}