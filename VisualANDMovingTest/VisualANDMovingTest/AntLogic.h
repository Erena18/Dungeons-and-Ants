#pragma once
#include "Vec2.h"
#include <cstdlib>

class AntLogic {
public:
    AntLogic(Vec2 startPos, float speed = 100.0f)
        : position(startPos), speed(speed), velocity(getRandomDirection()) {}

    void update(float dt, int width, int height);

    Vec2 getPosition() const { return position; }

private:
    Vec2 position;      //тек. позиция
    Vec2 velocity;      //направление движения
    float speed;        //скорость муравья

    //метод возвращает случайное направление для движения
    Vec2 getRandomDirection();
};