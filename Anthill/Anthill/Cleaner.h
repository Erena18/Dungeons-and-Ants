#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Builder.h"
#include "Child.h"
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

#include "Food.h"
#include "FoodItem.h"
#include "Anthill.h"

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Cleaner : public Role
{
public:
    virtual void Work() override;
    virtual void Eat(Ant& ant, Food& food) override;
    Cleaner(CleanerInformer* informer) : informer(informer) {}
    CleanerInformer* getInformer() const { return informer; }
    void setInformer(CleanerInformer* informer)
    {
        this->informer = informer;
    }
private:
    int maxDistance;            // Максимальное расстояние (15-35)
    bool helpRequested;         // Флаг запроса помощи
    CleanerInformer* informer;
};