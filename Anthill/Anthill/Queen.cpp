#include "Queen.h"

void Queen::Eat(Ant& ant, Food& food) 
{
	int foodRequired = 15;
	int hpRestoreAfterEating = 20;

	int consumed = food.consume(foodRequired);
	if (consumed > 0) 
	{
		ant.restoreHp(hpRestoreAfterEating);
	}
}

void Queen::Move(Ant& ant)
{
    ant.setTarget(ant.getPosition());
}

void Queen::Work(Ant& ant)
{
	ant.setTarget(ant.getPosition());
}