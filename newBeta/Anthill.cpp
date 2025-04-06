// Anthill.cpp
#include "Anthill.h"
#include "GarbageManager.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>

Anthill& Anthill::getInstance() {
    static Anthill instance;
    return instance;
}


Anthill::Anthill()
    : maxPopulation(12), durability(200), naturalDecayMin(1), naturalDecayMax(2) {
}



void Anthill::addAnt(std::unique_ptr<Ant> ant) {
    ants.push_back(std::move(ant));
}

void Anthill::addFood(int amount) {
    food.addFood(amount);
}

void Anthill::addMaterials(int amount) {
    materials.addMaterial(amount);
}

Food& Anthill::getFood() {
    return food;
}

Materials& Anthill::getMaterials() {
    return materials;
}

InformerCollector& Anthill::getInformerCollector() {
    return informerCollector;
}

InformerCleaner& Anthill::getInformerCleaner() {
    return informerCleaner;
}

Workshop& Anthill::getWorkshop() {
    return workshop;
}

Warehouse& Anthill::getWarehouse() {
    return warehouse;
}

CentralWarehouse& Anthill::getCentralWarehouse() {
    return centralWarehouse;
}

void Anthill::repair(int amount) {
    // Используем материалы для ремонта
    int materialsAvailable = materials.getAmount();
    int materialsToUse = std::min(amount, materialsAvailable);

    if (materialsToUse > 0) {
        materials.use(materialsToUse);
        durability += materialsToUse;

        // За каждые +25 единиц увеличения прочности +5 мест для жизни
        maxPopulation = 12 + ((durability - 200) / 25) * 5;
    }
}

void Anthill::receiveDamage(int amount) {
    durability -= amount;
    if (durability < 0) {
        durability = 0;
        // Обработка ситуации, когда муравейник полностью разрушен
    }

    // Обновляем максимальную вместимость
    maxPopulation = 12 + ((durability - 200) / 25) * 5;
}

bool Anthill::canAddAnt() const {
    return static_cast<int>(ants.size()) < maxPopulation;
}
void Anthill::dailyUpdate() {
    // Естественное разрушение
    int decay = naturalDecayMin + rand() % (naturalDecayMax - naturalDecayMin + 1);
    receiveDamage(decay);
    for (auto& ant : ants) {
        ant->growth();
        ant->Work();
        ant->Eat(food);
    }

    removeDeadAnts();
    // Обновляем постройки
    workshop.dailyUpdate();
    warehouse.dailyUpdate();
    centralWarehouse.dailyUpdate();
    food.dailyUpdate();
    materials.dailyUpdate();

    // Если мусора много, отправляем уведомление уборщикам
    if (GarbageManager::getInstance().getGarbageList().size() > 10) {
        informerCleaner.notify("Garbage accumulated, need cleaning!");
    }

}
void Anthill::removeDeadAnts() {
    for (auto it = ants.begin(); it != ants.end();) {
        if (!(*it)->isAlive()) {
            GarbageManager::getInstance().addGarbage(Garbage::Type::Corpse, 1);
            it = ants.erase(it);
        } else {
            ++it;
        }
    }
}
