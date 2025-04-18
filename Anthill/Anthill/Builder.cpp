#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Builder.h"

using namespace std;

void Builder::Eat(Ant& ant, Food& food)
{
	int foodRequired = 10;
	int hpLossWithoutFood = 5;
	int hpRestoreAfterEating = 10;

	int consumed = food.consume(foodRequired);
	if (consumed > 0)
	{
		ant.restoreHp(hpRestoreAfterEating);
	}
	else
	{
		ant.loseHp(hpLossWithoutFood);
	}
}

void Builder::Move(Ant& ant)
{
}

void Builder::Work(Ant& ant)
{
	if (workClock.getElapsedTime().asSeconds() >= workInterval)
	{
		workClock.restart();
		Anthill::getInstance().repair(3);
	}
}