// Cleaner.cpp
#include "Cleaner.h"
#include "Anthill.h"
#include "Ant.h"
#include "GarbageManager.h"
#include <cstdlib>

Cleaner::Cleaner()
    : healthLossPerDay(1 + rand() % 3) {
    maxDistance = 15 + rand() % 21; // 15-35
    informer = &Anthill::getInstance().getInformerCleaner();
    informer->subscribe(this);
}

Cleaner::~Cleaner() {
    informer->unsubscribe(this);
}

void Cleaner::Work(Ant& ant) {
    // Уборка мусора
    auto& garbageList = GarbageManager::getInstance().getGarbageList();
    if (!garbageList.empty()) {
        GarbageManager::getInstance().removeGarbage(0);
    }

    // Потеря здоровья
    ant.loseHp(healthLossPerDay);

    // Проверка здоровья
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
    // Обработка уведомления (логика по вашему усмотрению)
}