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