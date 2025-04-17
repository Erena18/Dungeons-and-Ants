#include "Heardsant.h"
#include "Anthill.h"
#include "AphidManager.h"

void Heardsant::Work(Ant& ant)
{
    Anthill& anthill = Anthill::getInstance();
    homePos = anthill.getCenter();

    if (waiting)
    {
        if (waitClock.getElapsedTime().asSeconds() >= 1.f)
        {
            waiting = false;
            goingToPasture = !goingToPasture;
            movementClock.restart();
            nextMoveInterval = 2.f + static_cast<float>(rand() % 1000) / 2000.f - 0.5f;
            ant.setTarget(goingToPasture ? pasturePos : homePos);
        }
        return;
    }

    if (movementClock.getElapsedTime().asSeconds() >= nextMoveInterval)
    {
        waiting = true;
        waitClock.restart();
    }

    ant.move();
}

void Heardsant::Eat(Ant& ant, Food& food)
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

void Heardsant::Move(Ant& ant)
{
    ant.move();
}
