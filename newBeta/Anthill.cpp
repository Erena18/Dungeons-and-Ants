// Anthill.cpp
#include "Anthill.h"
#include "GarbageManager.h"

Anthill& Anthill::getInstance() {
    static Anthill instance;
    return instance;
}

Anthill::Anthill() {}

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

void Anthill::dailyUpdate() {
    for (auto& ant : ants) {
        ant->growth();
        ant->Work();
        ant->Eat(food);
    }

    removeDeadAnts();

    food.dailyUpdate();
    materials.dailyUpdate();
}

void Anthill::removeDeadAnts() {
    for (auto it = ants.begin(); it != ants.end();) {
        if (!(*it)->isAlive()) {
            GarbageManager::getInstance().addGarbage(Garbage::Type::Corpse, 1);
            it = ants.erase(it);
        }
        else {
            ++it;
        }
    }
}
