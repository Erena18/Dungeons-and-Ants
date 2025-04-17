#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <SFML/System.hpp>

#include "Role.h"
#include "Ant.h"
#include "Child.h"
#include "Anthill.h"

using namespace std;
using namespace sf;


class Queen : public Role
{
public:
	void Work(Ant& ant) override;
	void Eat(Ant& ant, Food& food) override;
	void Move(Ant& ant) override;
private:
	Clock birthClock;
	float birthInterval = 6.f;
};