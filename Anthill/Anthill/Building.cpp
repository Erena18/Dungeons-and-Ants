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

Building::Building(int capacity, int count, int constructionCost): capacity(capacity), count(count), constructionCost(constructionCost) {}

int Building::getCapacity()const
{
    return capacity * count;
}

int Building::getCount() const 
{
    return count;
}

int Building::getConstructionCost() const 
{
    return constructionCost;
}