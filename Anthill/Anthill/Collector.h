#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Role.h"
#include "Ant.h"
#include "Informers.h"
#include "Zone.h"

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
