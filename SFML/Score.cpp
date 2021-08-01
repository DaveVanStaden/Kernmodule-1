//
// Created by davev on 31-7-2021.
//

#include "Score.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void Score::ScoreUp() {
    scoreCount+=1;
}
void Score::DisplayScore(sf::RenderWindow* RWindow, sf::Font font) {
    std::string scoreCountText(std::to_string(scoreCount));
    sf::Text scoreText("Current Score: " + scoreCountText,font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setStyle(sf::Text::Bold);
    scoreText.setPosition(0,0);
    RWindow->draw((scoreText));
}