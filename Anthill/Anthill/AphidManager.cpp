#include "AphidManager.h"

void AphidManager::add(Vector2f position)
{
	unique_ptr<Aphid> a = make_unique<Aphid>();
	a->setPosition(position);
	aphids.push_back(move(a));
}

void AphidManager::update(PastureZone& pasture, int& food)
{
	pasture.update();

	for (unique_ptr<Aphid>& a : aphids)
	{
		a->growthAphid(food);
		a->update(pasture);
		a->Eat(pasture.getFood());
	}
}

void AphidManager::draw(sf::RenderWindow& window)
{
	for (std::unique_ptr<Aphid>& a : aphids)
		a->draw(window);
}

void AphidManager::removeDead()
{
	for (size_t i = 0; i < aphids.size(); )
	{
		if (!aphids[i]->isAlive())
		{
			aphids.erase(aphids.begin() + i);
		}
		else
		{
			++i;
		}
	}
}
