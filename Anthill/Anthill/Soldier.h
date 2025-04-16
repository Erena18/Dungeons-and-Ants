#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Role.h"
#include "Ant.h"

using namespace std;

class Ant;

class Soldier : public Role
{
public:
    Soldier();

    void Work(Ant& ant) override;
    void Eat(Ant& ant, Food& food) override;
    void Move(Ant& ant) override;
private:
    float patrolRadius = 100.f;
};