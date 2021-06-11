#include "Vector2.h"
Vector2::Vector2() : x(0), y(0)
{ }

Vector2::Vector2(float _x, float _y)
        : x(_x), y(_y)
{ }

Vector2::~Vector2()
{ }

float Vector2::GetX() const
{
    return x;
}

float Vector2::GetY() const
{
    return y;
}

void Vector2::SetX(const float _x)
{
    x = _x;
}

void Vector2::SetY(const float _y)
{
    y = _y;
}
