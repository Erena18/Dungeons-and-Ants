#include "FoodItem.h"

using namespace std;

FoodItem::FoodItem(int amount) : amount(amount), age(0)
{
    shape.setRadius(5.f);
    shape.setFillColor(Color::Yellow);
    shape.setOrigin(5.f, 5.f);
}

int FoodItem::getAmount() const 
{
    return amount;
}

int FoodItem::getAge() const 
{
    return age;
}

void FoodItem::increaseAge() 
{
    age++;
}

bool FoodItem::isSpoiled() const 
{
    return age >= 10;
}

void FoodItem::reduceAmount(int amountToReduce) 
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

void FoodItem::setPosition(Vector2f pos)
{
    shape.setPosition(pos);
}

void FoodItem::draw(RenderWindow& window) const
{
    window.draw(shape);
}

Vector2f FoodItem::getPosition() const
{
    return shape.getPosition();
}
