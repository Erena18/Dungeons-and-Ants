#include "Queen.h"

void Queen::Eat(Ant& ant, Food& food) 
{
	int foodRequired = 30;
	int hpLossWithoutFood = 15;
	int hpRestoreAfterEating = 20;

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

/*void Queen::Move(Ant& ant)
{
	ant.setTarget(ant.getPosition());
}*/

void Queen::Work(Ant& ant)
{
	Anthill& anthill = Anthill::getInstance();
	if (!anthill.canAddAnt()) 
	{
		return;
	}
	int count = rand() % 9 + 3;
	/*for (int i = 0; i < count && anthill.canAddAnt(); ++i) {
		auto newAnt = make_unique<Ant>(100, 0, std::make_unique<Child>(), anthill.getData());
		newAnt->setPosition(anthill.getCenter());
		anthill.addAnt(move(newAnt));
	}*/

	for (int i = 0; i < count && anthill.canAddAnt(); ++i)
	{
		unique_ptr<Ant> newAnt = make_unique<Ant>(100, 0, make_unique<Child>());
		anthill.addAnt(move(newAnt));
	}
}