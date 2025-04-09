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
#include "Collector.h"

#include "Food.h"
#include "FoodItem.h"
#include "Anthill.h"

#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
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

Collector::Collector()
    : cargoCapacity(3), healthLossPerDay(1 + rand() % 3), helpRequested(false) {
    informer = &Anthill::getInstance().getInformerCollector();
    informer->subscribe(this);
}

Collector::~Collector() {
    informer->unsubscribe(this);
}

void Collector::Work() 
{
    int foundResources, foundMaterials;

    if (helpRequested) {
        foundResources = rand() % 3;
        foundMaterials = rand() % 2;
        helpRequested = false;
    }
    else {
        foundResources = rand() % 5;
        foundMaterials = rand() % 3;
    }

    int totalFound = foundResources + foundMaterials;
    int capacityLeft = cargoCapacity;

    if (totalFound > 0) {
        int cargoResources = std::min(foundResources, capacityLeft);
        capacityLeft -= cargoResources;
        int cargoMaterials = std::min(foundMaterials, capacityLeft);
        capacityLeft -= cargoMaterials;

        Anthill::getInstance().addFood(cargoResources);
        Anthill::getInstance().addMaterials(cargoMaterials);

        if (totalFound > cargoCapacity) {
            // Оповещаем других собирателей
            informer->notify("Collector needs help collecting resources!");
        }
    }

}



void Collector::receiveNotification(const std::string& message) {
    if (message == "Collector needs help collecting resources!") {
        helpRequested = true;
    }
}