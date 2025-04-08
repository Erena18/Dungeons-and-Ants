#include "AntLogic.h"
#include <cstdlib>

Vec2 AntLogic::getRandomDirection()
{
    float angle = static_cast<float>(rand()) / RAND_MAX * 2 * 3.14159f;
    return Vec2(std::cos(angle), std::sin(angle));
}

void AntLogic::update(float dt, int width, int height)
{
    Vec2 displacement = velocity.scale(speed * dt);
    position = position.add(displacement);

    float x = position.getX();
    float y = position.getY();

    if (x < 0 || x > width) velocity = Vec2(-velocity.getX(), velocity.getY());
    if (y < 0 || y > height) velocity = Vec2(velocity.getX(), -velocity.getY());
}