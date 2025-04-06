#include "Anthill.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>

Anthill* Anthill::instance = nullptr;

Anthill& Anthill::getInstance() {
    if (!instance) {
        instance = new Anthill();
    }
    return *instance;
}

Anthill::Anthill()
    : food(100) {
}

void Anthill::addAnt(std::unique_ptr<Ant> ant) {
    ants.push_back(std::move(ant));
}

void Anthill::removeDeadAnts() {
    ants.erase(std::remove_if(ants.begin(), ants.end(),
        [](const std::unique_ptr<Ant>& ant) { return ant->getHp() <= 0 || ant->getAge() > 100; }), ants.end());
}

void Anthill::dailyUpdate() {
    for (auto& ant : ants) {
        ant->Eat(food);
        ant->Work();
        ant->growth();
        ant->loseHpEndDay();
    }
    removeDeadAnts();
}

void Anthill::addFoodSupply(int amount) {
    food.addFood(amount);
}