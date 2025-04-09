#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collector.h"
#include "Heardsant.h"
#include "Nanny.h"
#include "Queen.h"
#include "Soldier.h"

#include "Anthill.h"
#include "Building.h"
#include "Food.h"
#include "FoodItem.h"
#include "Garbage.h"
#include "GarbageManager.h"
#include "Materials.h"
#include "MaterialsItem.h"
#include "Warehouse.h"

#include "Zone.h"
#include "DangerousZone.h"
#include "EmptyZone.h"
#include "FoodZone.h"
#include "MaterialZone.h"
#include "PastureZone.h"

#include "AntLogic.h"
#include "Dimensions.h"

#include "Informers.h"

#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

MaterialItem::MaterialItem(int amount) : amount(amount), age(0) {}

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
    return age >= 10;
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