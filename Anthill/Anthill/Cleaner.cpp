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

void Cleaner::Eat(Ant& ant, Food& food)
{
    int foodRequired = 10;
    int hpLossWithoutFood = 10;
    int hpRestoreAfterEating = 15;

    int consumed = food.consume(foodRequired);
    if (consumed > 0)
    {
        ant.restoreHp(hpRestoreAfterEating);
    }
    else
    {
        ant.loseHp(hpLossWithoutFood);
    }
}


void Cleaner::Work() 
{
    int garbageToClean = 1;

    if (helpRequested) 
    {
        garbageToClean = 2; // Убираем больше мусора
        helpRequested = false;
    }

    auto& garbageList = GarbageManager::getInstance().getGarbageList();
    int actualGarbageToClean = min(garbageToClean, static_cast<int>(garbageList.size()));
    for (int i = 0; i < actualGarbageToClean; ++i)
    {
        GarbageManager::getInstance().removeGarbage(0);
    }

    // Если после уборки мусор всё ещё есть
    if (garbageList.size() > actualGarbageToClean)
    {
        CleanerInformer* cleanerInformer = getInformer();
        if (cleanerInformer)
        {
            cleanerInformer->notify(); //вызов сборщиков
            helpRequested = true;
        }
    }
}
