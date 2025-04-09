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

GarbageManager& GarbageManager::getInstance() 
{
    static GarbageManager instance;
    return instance;
}

void GarbageManager::addGarbage(Garbage::Type type, int weight) 
{
    garbageList.emplace_back(type, weight);
}

void GarbageManager::removeGarbage(int index) 
{
    if (index >= 0 && index < static_cast<int>(garbageList.size())) 
    {
        garbageList.erase(garbageList.begin() + index);
    }
}

const vector<Garbage>& GarbageManager::getGarbageList() const 
{
    return garbageList;
}