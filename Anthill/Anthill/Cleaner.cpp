#include "Cleaner.h"

Cleaner::Cleaner()
{
    dumpPos = sf::Vector2f(800.f, 300.f);
    dumpArea.setSize({ 40.f, 40.f });
    dumpArea.setFillColor(sf::Color::Black);
    dumpArea.setPosition(dumpPos);
}

void Cleaner::Eat(Ant& ant, Food& food)
{
    int foodRequired = 10;
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

void Cleaner::Move(Ant& ant)
{
    ant.move();
}

void Cleaner::drawDump(sf::RenderWindow& window)
{
    window.draw(dumpArea);
}

void Cleaner::Work(Ant& ant)
{
    auto& garbageList = GarbageManager::getInstance().getGarbageList();
    if (!garbageList.empty())
    {
        GarbageManager::getInstance().removeGarbage(1);
        return;
    }

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
