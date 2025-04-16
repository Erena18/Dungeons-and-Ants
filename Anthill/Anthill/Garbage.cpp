#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Garbage.h"

using namespace std;

Garbage::Garbage(Type type, int weight): type(type), weight(weight)
{
    shape.setRadius(4.f);
    shape.setOrigin(4.f, 4.f);
    shape.setPosition(position);

    switch (type)
    {
    case Type::RottenFood:
        shape.setFillColor(sf::Color(150, 75, 0)); // коричневый
        break;
    case Type::RottenMaterial:
        shape.setFillColor(sf::Color(128, 128, 128)); // серый
        break;
    case Type::Corpse:
        shape.setFillColor(sf::Color::Black);
        break;
    }
}

Garbage::Type Garbage::getType() const 
{
    return type;
}

int Garbage::getWeight() const 
{
    return weight;
}

void Garbage::setPosition(Vector2f pos)
{
    position = pos;
    shape.setPosition(pos);
}

void Garbage::draw(RenderWindow& window) const
{
    window.draw(shape);
}
