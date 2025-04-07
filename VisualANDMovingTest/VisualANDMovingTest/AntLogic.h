#pragma once
#include "Vec2.h"
#include <cstdlib>

class AntLogic {
private:
    Vec2 position;
    Vec2 velocity;
    float speed;

    Vec2 getRandomDirection() {
        float angle = static_cast<float>(rand()) / RAND_MAX * 2 * 3.14159f;
        return Vec2(std::cos(angle), std::sin(angle));
    }

public:
    AntLogic(Vec2 startPos, float speed = 50.0f)
        : position(startPos), speed(speed), velocity(getRandomDirection()) {
    }

    void update(float dt, int width, int height) {
        Vec2 displacement = velocity.scale(speed * dt);
        position = position.add(displacement);

        float x = position.getX();
        float y = position.getY();

        if (x < 0 || x > width) velocity = Vec2(-velocity.getX(), velocity.getY());
        if (y < 0 || y > height) velocity = Vec2(velocity.getX(), -velocity.getY());
    }

    Vec2 getPosition() const { return position; }
};