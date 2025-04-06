// Cleaner.cpp
#include "Cleaner.h"
#include "Anthill.h"
#include "Ant.h"
#include "GarbageManager.h"
#include <cstdlib>

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
    if (!garbageList.empty()) {
        informer->notify("Cleaner needs help cleaning garbage!");
    }

    ant.loseHp(healthLossPerDay);

    if (ant.getHp() <= 5) {
        ant.die();
    }
}

void Cleaner::Eat(Ant& ant, Food& food) {
    int requiredFood = 10 + rand() % 6; // 10-15 единиц
    int consumed = food.consume(requiredFood);
    if (consumed > 0) {
        ant.restoreHp(15);
    }
    else {
        ant.loseHp(10);
    }
}

void Cleaner::receiveNotification(const std::string& message) {
    if (message == "Cleaner needs help cleaning garbage!") {
        helpRequested = true;
    }
}