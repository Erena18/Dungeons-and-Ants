#include "Collector.h"

Collector::Collector(float gatherRadius) : radius(gatherRadius) {}

void Collector::setFoodItems(vector<FoodItem>* foods)
{
    foodItems = foods;
}

void Collector::setMaterialItems(vector<MaterialItem>* mats)
{
    materialItems = mats;
}

void Collector::setHomePosition(const Vector2f& home)
{
    homePos = home;
}

void Collector::Work(Ant& ant)
{
	auto pos = ant.getPosition();

	if (!carrying)
	{
		if (foodItems)
		{
			for (auto it = foodItems->begin(); it != foodItems->end(); ++it)
			{
				Vector2f itemPos = it->getPosition();
				float dx = pos.x - itemPos.x, dy = pos.y - itemPos.y;
				if (std::sqrt(dx * dx + dy * dy) <= radius)
				{
					carriedFood = it->getAmount();
					foodItems->erase(it);
					carrying = true;
					ant.setTarget(homePos);
					return;
				}
			}
		}

		if (materialItems)
		{
			for (auto it = materialItems->begin(); it != materialItems->end(); ++it)
			{
				Vector2f itemPos = it->getPosition();
				float dx = pos.x - itemPos.x, dy = pos.y - itemPos.y;
				if (std::sqrt(dx * dx + dy * dy) <= radius)
				{
					carriedMaterials = it->getAmount();
					materialItems->erase(it);
					carrying = true;
					ant.setTarget(homePos);
					return;
				}
			}
		}

		if (ant.getTarget() == homePos || ant.getTarget() == Vector2f(0.f, 0.f))
		{
			ant.setRandomDirection();
			Vector2f wanderTarget = pos + ant.getRandomDirection() * 100.f;
			ant.setTarget(wanderTarget);
		}

		ant.move();
	}
	else
	{
		float dx = pos.x - homePos.x, dy = pos.y - homePos.y;
		if (std::sqrt(dx * dx + dy * dy) <= radius)
		{
			Anthill::getInstance().addFood(carriedFood);
			Anthill::getInstance().addMaterials(carriedMaterials);
			carrying = false;
			carriedFood = carriedMaterials = 0;
			ant.setTarget({});
		}
		else
		{
			ant.setTarget(homePos);
			ant.move();
		}
	}
}


void Collector::Eat(Ant& ant, Food& food)
{
    int foodRequired = 15;
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