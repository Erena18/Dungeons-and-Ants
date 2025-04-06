// Collector.cpp
#include "Collector.h"
#include "Anthill.h"
#include "Ant.h"
#include "Materials.h"
#include <cstdlib>
#include <algorithm>

Collector::Collector()
    : cargoCapacity(3), healthLossPerDay(1 + rand() % 3), helpRequested(false) {
    informer = &Anthill::getInstance().getInformerCollector();
    informer->subscribe(this);
}

Collector::~Collector() {
    informer->unsubscribe(this);
}

void Collector::Work(Ant& ant) {
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

    ant.loseHp(healthLossPerDay);
}

void Collector::Eat(Ant& ant, Food& food) {
    int requiredFood = 15;
    int consumed = food.consume(requiredFood);
    if (consumed > 0) {
        ant.restoreHp(15);
    }
    else {
        ant.loseHp(10);
    }
}

void Collector::receiveNotification(const std::string& message) {
    if (message == "Collector needs help collecting resources!") {
        helpRequested = true;
    }
}