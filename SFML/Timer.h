//
// Created by davev on 1-8-2021.
//

#ifndef SFML_TIMER_H
#define SFML_TIMER_H
#include <SFML/Graphics.hpp>

class Timer {
public:
    void CountDown(sf::RenderWindow* RWindow, sf::Font font);
    float time = 60;
    bool EndGame = false;
private:
};


#endif //SFML_TIMER_H
