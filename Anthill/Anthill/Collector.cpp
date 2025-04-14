#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Collector.h"

using namespace std;

void Collector::Eat(Ant& ant, Food& food)
{
    int foodRequired = 15;
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

void Collector::Work() 
{
    Zone* currentZone = getCurrentZone(); // ньхайю
    //еякх гнмю ме нопедекемю опнднкфюел дбхфемхе

    int foundResources = 0, foundMaterials = 0;

    if (currentZone->getType() == "Food")
    {
        if (!currentZone->isEmpty())
        {
            foundResources = rand() % 5; //нрйюкхапнбюрэ
            currentZone->onAntEnter();
        }
    }
    else if (currentZone->getType() == "Material")
    {
        if (!currentZone->isEmpty())
        {
            foundMaterials = rand() % 3; //нрйюкхапнбюрэ
            currentZone->onAntEnter();
        }
    }

    int totalFound = foundResources + foundMaterials;
    int capacityLeft = cargoCapacity;

    if (totalFound > 0) 
    {
        int cargoResources = min(foundResources, capacityLeft);
        capacityLeft -= cargoResources;
        int cargoMaterials = min(foundMaterials, capacityLeft);
        capacityLeft -= cargoMaterials;

        Anthill::getInstance().addFood(cargoResources);
        Anthill::getInstance().addMaterials(cargoMaterials);

        if (totalFound > cargoCapacity) 
        {
            CollectorInformer* collectorInformer = getInformer();
            if (collectorInformer)
            {
                collectorInformer->notify(); //БШГНБ ЯАНПЫХЙНБ
                helpRequested = true;
            }
        }
    }
}
