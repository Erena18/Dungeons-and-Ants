#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "Food.h"

using namespace std;
using namespace sf;

// Пастбищная зона
class PastureZone
{
public:
    PastureZone(Vector2f position, Vector2f size);
    void update();
    void draw(RenderWindow& window) const;

    Food& getFood() { return food; }
    const Vector2f& getPosition() const { return area.getPosition(); }

private:
    RectangleShape area;
    Food food;

    Clock regenClock;
    float regenInterval = 10.f;
    int maxFoodAmount = 20;
};
