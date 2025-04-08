#include "Anthill.h"
#include "Building.h"
#include "Warehouse.h"
#include "Food.h"
#include "FoodItem.h"
#include "Materials.h"
#include "MaterialsItem.h"
#include "Garbage.h"
#include "GarbageManager.h"
#include "Workshop.h"

#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

FoodItem::FoodItem(int amount) : amount(amount), age(0) {}

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