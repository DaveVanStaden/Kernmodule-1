#ifndef UNTITLED_VECTOR2_H
#define UNTITLED_VECTOR2_H

#include <iostream>

class Vector2{
public:
    float x;
    float y;
    Vector2();
    Vector2(float x, float y);
    ~Vector2();

    float GetX() const;
    float GetY() const;

    void SetX(const float x);
    void SetY(const float y);
    bool collisionDetection(Vector2 player, Vector2 enemy, float radiusPlayer, float radiusEnemy);
private:
};

#endif //UNTITLED_VECTOR2_H