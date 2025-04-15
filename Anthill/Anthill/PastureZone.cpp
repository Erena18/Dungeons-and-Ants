#include "PastureZone.h"

PastureZone::PastureZone(Vector2f position, Vector2f size)
{
    area.setSize(size);
    area.setPosition(position);
    area.setFillColor(Color(144, 238, 144));
    area.setOutlineThickness(1.f);
    area.setOutlineColor(Color::Green);
    food.addFood(maxFoodAmount);
}

void PastureZone::update()
{
    if (regenClock.getElapsedTime().asSeconds() >= regenInterval)
    {
        if (food.getTotalAmount() < maxFoodAmount)
        {
            food.addFood(1);
        }
        regenClock.restart();
    }
}

void PastureZone::draw(RenderWindow& window) const
{
    window.draw(area);
}
