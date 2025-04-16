#include "Aphid.h"

Aphid::Aphid() : hpAphid(20), ageAphid(0)
{
	shape.setRadius(4.f);
	shape.setFillColor(Color::Magenta);
	shape.setOrigin(4.f, 4.f);
	homePosition = { 400.f, 300.f };
	shape.setPosition(homePosition);
}

void Aphid::growthAphid(Food& food)
{
	ageAphid++;
	if ((hpAphid <= 0) || (ageAphid > 10))
	{
		dieAphid(food);
	}
}

void Aphid::dieAphid(Food& food)
{
	if (isOnPasture)
		GarbageManager::getInstance().addGarbage(Garbage::Type::Corpse, 1);
	else
		food.addFood(1);

	hpAphid = 0;
}

void Aphid::loseHpAphid(int damageHp, Food& food)
{
	hpAphid -= damageHp;
	if (hpAphid < 0)
	{
		dieAphid(food);
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

void Aphid::update(PastureZone& pasture)
{
	isOnPasture = true;

	// Тут можно добавить логику "пасения", взаимодействия с Heardsant и т.д.
	// Пока ничего не делает — просто помечает, что тля активна.
}

bool Aphid::isAlive() const
{
	return hpAphid > 0;
}

int Aphid::getHp() const
{
	return 0;
}

int Aphid::getAge() const
{
	return 0;
}

Vector2f Aphid::getPosition() const
{
	return shape.getPosition();
}

void Aphid::setPosition(Vector2f pos)
{
	shape.setPosition(pos);
}

void Aphid::draw(RenderWindow& window) const
{
	if (isAlive())
		window.draw(shape);
}

