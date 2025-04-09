#pragma once

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

#include "DangerousZone.h"
#include "EmptyZone.h"
#include "FoodZone.h"
#include "MaterialZone.h"
#include "PastureZone.h"

#include "AntLogic.h"
#include "Dimensions.h"

#include "Informers.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
using namespace std;

class Ant;
class Anthill;

class Zone 
{
public:
    virtual ~Zone() = default;

    // Обновление состояния зоны
    virtual void update() = 0;
    virtual string getType() const = 0;
    virtual bool isEmpty() const { return false; }
    virtual void onAntEnter() = 0;
};

class ZoneManager 
{
public:
    static ZoneManager& getInstance()
    {
        static ZoneManager instance;
        return instance;
    }
    Zone* getCurrentZone(Ant& ant) 
    {
       // логика определение текущей зоны (поля) на основе состояния муравья
        return currentZone;
    }

private:
    Zone* currentZone;
};