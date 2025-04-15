#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "MaterialsItem.h"

using namespace std;

MaterialItem::MaterialItem(int amount) : amount(amount), age(0)
{
    shape.setRadius(5.f);
    shape.setFillColor(Color(139, 69, 19));
    shape.setOrigin(5.f, 5.f);
}

int MaterialItem::getAmount() const 
{
    return amount;
}

int MaterialItem::getAge() const 
{
    return age;
}

void MaterialItem::increaseAge() 
{
    age++;
}

bool MaterialItem::isSpoiled() const 
{
    return age >= 20;
}

void MaterialItem::reduceAmount(int amountToReduce) 
{
    if (amountToReduce >= amount) 
    {
        amount = 0;
    }
    else 
    {
        amount -= amountToReduce;
    }
}

void MaterialItem::setPosition(Vector2f pos)
{
    shape.setPosition(pos);
}

void MaterialItem::draw(RenderWindow& window) const
{
    window.draw(shape);
}
