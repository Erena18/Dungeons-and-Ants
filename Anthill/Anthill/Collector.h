#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Nanny.h"
#include "Child.h"
#include "Queen.h"
#include "Builder.h"
#include "Cleaner.h"
#include "Soldier.h"
#include "Heardsant.h"
#include "Informers.h"

#include "Food.h"
#include "FoodItem.h"
#include "Anthill.h"

#include  "Zone.h"
#include  "DangerousZone.h"
#include  "FoodZone.h"
#include  "MaterialZone.h"

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
