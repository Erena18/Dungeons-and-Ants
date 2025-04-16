#include "Soldier.h"

Soldier::Soldier()
{
}

void Soldier::Work(Ant& ant)
{
    Move(ant);
}

void Soldier::Eat(Ant& ant, Food& food)
{
    int foodRequired = 20;
    int hpLossWithoutFood = 15;
    int hpRestoreAfterEating = 30;

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

void Soldier::Move(Ant& ant)
{
    Vector2f pos = ant.getPosition();
    Vector2f target = ant.getTarget();

    float dx = target.x - pos.x;
    float dy = target.y - pos.y;
    float dist = std::sqrt(dx * dx + dy * dy);

    if (dist < 5.f || target == Vector2f(0.f, 0.f))
    {
        // Задать новое случайное направление в пределах патруля
        ant.setRandomDirection();
        Vector2f newTarget = pos + ant.getRandomDirection() * patrolRadius;
        ant.setTarget(newTarget);
    }

    ant.move();
}
