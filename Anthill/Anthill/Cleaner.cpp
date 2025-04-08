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

Cleaner::Cleaner()
    : healthLossPerDay(1 + rand() % 3), helpRequested(false) {
    maxDistance = 15 + rand() % 21; // 15-35
    informer = &Anthill::getInstance().getInformerCleaner();
    informer->subscribe(this);
}

Cleaner::~Cleaner() {
    informer->unsubscribe(this);
}

void Cleaner::Work(Ant& ant) {
    int garbageToClean = 1;

    if (helpRequested) {
        garbageToClean = 2; // Убираем больше мусора
        helpRequested = false;
    }

    auto& garbageList = GarbageManager::getInstance().getGarbageList();
    for (int i = 0; i < garbageToClean && !garbageList.empty(); ++i) {
        GarbageManager::getInstance().removeGarbage(0);
    }

    // Если после уборки мусор всё ещё есть
    if (!garbageList.empty()) 
    {
        informer->notify("Cleaner needs help cleaning garbage!");
    }

    ant.loseHp(healthLossPerDay);
    if (ant.getHp() <= 5) {
        ant.die();
    }
}


void Cleaner::receiveNotification(const std::string& message) {
    if (message == "Cleaner needs help cleaning garbage!") {
        helpRequested = true;
    }
}