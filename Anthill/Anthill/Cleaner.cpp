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
    }
}
