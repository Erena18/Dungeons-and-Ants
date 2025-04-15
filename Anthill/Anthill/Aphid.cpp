#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Aphid.h"

using namespace std;

Aphid::Aphid() : hpAphid(20), ageAphid(0)
{
	shape.setRadius(4.f);
	shape.setFillColor(Color::Magenta);
	shape.setOrigin(4.f, 4.f);
	homePosition = { 400.f, 300.f };
	shape.setPosition(homePosition);
}

void Aphid::growthAphid(int& amountFood)
{
	ageAphid++;
	if ((hpAphid <= 0) || (ageAphid > 10))
	{
		dieAphid(amountFood);
	}
}

void Aphid::dieAphid(int& amountFood)
{
	if (isOnPasture)
		GarbageManager::getInstance().addGarbage(Garbage::Type::Corpse, 1);
	else
		amountFood++;
	hpAphid = 0;
}

void Aphid::loseHpAphid(int damageHp, int& amountFood)
{
	hpAphid -= damageHp;
	if (hpAphid < 0)
	{
		//int countFood = getAmountFood();
		dieAphid(amountFood);
	}
}

void Aphid::restoreHpAphid(int point)
{
	hpAphid += point;
	if (hpAphid > 20)
	{
		hpAphid = 20;
	}
}

void Aphid::Eat(Food& food)
{
	if (!isOnPasture)
		return;
	int consumed = food.consume(1);
}

bool Aphid::isAlive()
{
	return false;
}

int Aphid::getHp() const
{
	return 0;
}

int Aphid::getAge() const
{
	return 0;
}

void Aphid::setPosition(Vector2f pos)
{
}

void Aphid::draw(RenderWindow& window) const
{
}

void Aphid::update(PastureZone& pasture)
{
}
