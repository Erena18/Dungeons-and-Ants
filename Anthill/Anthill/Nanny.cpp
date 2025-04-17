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
    Vector2f pos = ant.getPosition();
    Vector2f target = ant.getTarget();

    float dx = target.x - pos.x;
    float dy = target.y - pos.y;
    float dist = std::sqrt(dx * dx + dy * dy);

    if (dist < 5.f || target == Vector2f(0.f, 0.f)) {
        Vector2f center = Anthill::getInstance().getCenter();
        float radius = Anthill::getInstance().getNestRadius(); 

        float angle = static_cast<float>(rand()) / RAND_MAX * 2 * 3.1415926f;
        float r = static_cast<float>(rand()) / RAND_MAX * (radius - 10.f);
        Vector2f newTarget = center + Vector2f(std::cos(angle), std::sin(angle)) * r;

        ant.setTarget(newTarget);
    }

    ant.move();
}