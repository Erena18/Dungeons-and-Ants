#include "Nanny.h"

Nanny::Nanny() {}

void Nanny::Eat(Ant& ant, Food& food)
{
	int foodRequired = 7;
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

void Nanny::Move(Ant& ant)
{
}

void Nanny::Work(Ant& ant)
{
    /*vector<Child*> children;
    for (Child* child : children)
    {
        Vec2 childPosition = child->getPosition();
        float distance = sqrt(pow(position.getX() - childPosition.getX(), 2) +
            pow(position.getY() - childPosition.getY(), 2));
        if (distance > 10.0f)
        {
            targetPosition = childPosition;
            isMoving = true;
            return;
        }
    }
}*/
}