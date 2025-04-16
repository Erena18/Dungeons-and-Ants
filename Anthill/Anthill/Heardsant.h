#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"

using namespace std;

class Heardsant : public Role
{
public:
    void Work(Ant& ant) override;
    void Eat(Ant& ant, Food& food) override;
    void Move(Ant& ant) override;

private:
    float searchRadius = 50.f;
    Vector2f targetPos;
    bool movingToAphid = false;
};