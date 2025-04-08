#include "AntLogic.h"
#include <cstdlib>
#include <cmath>

using namespace std;

Vec2 AntLogic::getRandomDirection()
{
    float angle = static_cast<float>(rand()) / RAND_MAX * 2 * 3.14159f;
    return Vec2(cos(angle), sin(angle));
}

void AntLogic::update(float dt, int width, int height)
{
    Vec2 displacement = velocity.scale(speed * dt);
    position = position.add(displacement);

    float distanceFromStart = sqrt(std::pow(position.getX() - initPosition.getX(), 2) +
        pow(position.getY() - initPosition.getY(), 2));

    if (distanceFromStart >= maxDistance && kudaSobralsya) {
        kudaSobralsya = false;  //shlepaem obratno
        //velocity = initPosition.add(position.scale(-1));  //vertai v zad
        Vec2 direction = initPosition.add(position.scale(-1));
        float length = std::sqrt(direction.getX() * direction.getX() + direction.getY() * direction.getY());
        velocity = direction.scale(1.0f / length);
    }

    if (distanceFromStart <= 0.5f && !kudaSobralsya) {
        kudaSobralsya = true;  //pshel von
        velocity = getRandomDirection();  // kuda glaza glyadyat
    }

    // okno zarkroy, ot Evropi vinyaet
    if (position.getX() < 0 || position.getX() > width) velocity = Vec2(-velocity.getX(), velocity.getY());
    if (position.getY() < 0 || position.getY() > height) velocity = Vec2(velocity.getX(), -velocity.getY());
}