//
// Created by davev on 31-7-2021.
//

#ifndef SFML_SCORE_H
#define SFML_SCORE_H
#include <SFML/Graphics.hpp>

class Score {
public:
    void ScoreUp();
    void DisplayScore(sf::RenderWindow* RWindow, sf::Font font);
    float scoreCount;
private:
};


#endif //SFML_SCORE_H
