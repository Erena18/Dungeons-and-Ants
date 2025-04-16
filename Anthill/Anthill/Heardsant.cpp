#include "Heardsant.h"
#include "Anthill.h"
#include "AphidManager.h"

void Heardsant::Work(Ant& ant)
{
    Vector2f antPos = ant.getPosition();

    // Пример поиска ближайшей тли
    AphidManager& aphidManager = Anthill::getInstance().getAphidManager();
    auto& aphids = aphidManager.getAphids(); 

    for (auto& aphid : aphids)
    {
        if (!aphid->isAlive()) continue;

        Vector2f pos = aphid->getPosition();
        float dx = pos.x - antPos.x;
        float dy = pos.y - antPos.y;
        float dist = sqrt(dx * dx + dy * dy);

        if (dist <= searchRadius)
        {
            targetPos = pos;
            movingToAphid = true;
            ant.setTarget(targetPos);
            return;
        }
    }

    ant.setRandomDirection();
    Vector2f wander = antPos + ant.getRandomDirection() * 50.f;
    ant.setTarget(wander);
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
