#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Builder.h"
#include "Child.h"
#include "Cleaner.h"
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
#include <memory>
#include <vector>
using namespace std;

class Collector : public Role 
{
public:
    virtual void Work() override;
    void Eat(Ant& ant, Food& food) override;
    Collector(CollectorInformer* informer) : informer(informer) {}
    CollectorInformer* getInformer() const { return informer; }
    void setInformer(CollectorInformer* informer)
    {
        this->informer = informer;
    }

private:
    int cargoCapacity;          // макс грузоподъем
    CollectorInformer* informer;
    bool helpRequested;         // Флаг о помощи
    Zone* getCurrentZone(Ant& ant) 
    {
        return ZoneManager::getInstance().getCurrentZone(ant); // Получаем текущую зону через менеджер зон
    }
};
