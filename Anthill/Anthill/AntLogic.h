#pragma once
#include "Dimensions.h"
#include <cstdlib>

class AntLogic {
public:
    AntLogic(Vec2 startPos, float speed = 50.0f, float maxDist = 400.0f)
        : position(startPos), initPosition(startPos), speed(speed),
        maxDistance(maxDist), kudaSobralsya(true) {
        velocity = getRandomDirection();
    }

    void update(float dt, int width, int height);

    Vec2 getPosition() const { return position; }
    Vec2 getVelocity() const { return velocity; }

private:
    Vec2 position;      //current position
    Vec2 initPosition;      //start (nest)
    Vec2 velocity;      //direction
    float speed;        //speed
    float maxDistance;
    bool kudaSobralsya;

    //метод возвращает случайное направление для движения
    Vec2 getRandomDirection();
};