#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include <vector>

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"

using namespace std;
using namespace sf;

class Heardsant : public Role
{
public:
    void Work(Ant& ant) override;
    void Eat(Ant& ant, Food& food) override;
    void Move(Ant& ant) override;

private:
    Vector2f pasturePos = { 1000.f, 600.f };
    Vector2f homePos; 
    bool goingToPasture = true;
    bool waiting = false;

    Clock movementClock;
    Clock waitClock;
    float nextMoveInterval =
        2.f + static_cast<float>(rand() % 1000) / 2000.f - 0.5f;
};