#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Builder.h"

using namespace std;

void Builder::Eat(Ant& ant, Food& food)
{
	int foodRequired = 20;
	int hpLossWithoutFood = 10;
	int hpRestoreAfterEating = 15;

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
	Anthill::getInstance().repair(5);
}