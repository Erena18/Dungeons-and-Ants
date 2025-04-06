#include "Collector.h"
#include "Anthill.h"
#include <iostream>
#include <cstdlib>

Collector::Collector(Anthill* anthill, int age, int health)
    : anthill(anthill), age(age), health(health), cargoCapacity(3), cargo(0), state("Idle") {
    // Initialization
}

Collector::~Collector() {
    // Destructor
}

void Collector::dailyUpdate() {
    age++;

    int healthLoss = rand() % 3 + 1;
    health -= healthLoss;

    if (health <= 0) {
        std::cout << "A collector has died of exhaustion.\n";
        return;
    }

    work();
}

void Collector::work() {
    std::cout << "Collector is going scouting.\n";

    int foundResources = rand() % 6;
    int foundMaterials = rand() % 2 == 0 ? rand() % 4 : 0;

    if (foundResources > 0) {
        if (foundResources <= cargoCapacity) {
            cargo += foundResources;
            std::cout << "Collector gathered " << foundResources << " units of food.\n";
            anthill->addFoodSupply(cargo);
            cargo = 0;
        }
        else {
            cargo += cargoCapacity;
            std::cout << "Collector found " << foundResources << " units of food, calling for help.\n";
            anthill->addFoodSupply(cargo);
            cargo = 0;
            anthill->callForCollectorHelp();
        }
    }

    if (foundMaterials > 0) {
        std::cout << "Collector found " << foundMaterials << " units of materials.\n";
        anthill->addMaterials(foundMaterials);
    }
    

    // ÃŒﬂ ÿ»«¿, ÃŒ∆≈“ À”◊ÿ≈ ›“Œ » Õ≈ ƒŒ¡¿¬Àﬂ“‹
    int chance = rand() % 100;
    if (chance < 60) {
        std::cout << "Collector became a thief on foreign territory!\n";
        // ƒÓÔÓÎÌËÚÂÎ¸Ì‡ˇ ÎÓ„ËÍ‡ ‰Îˇ ‚Ó‡
    }

    chance = rand() % 100;
    if (chance < 20) {
        std::cout << "Collector discovered a dangerous zone and alerts warriors!\n";
        anthill->alertWarriors();
    }
}

//  ŒÕ≈÷ ÿ»«€


int Collector::getAge() const {
    return age;
}

int Collector::getHealth() const {
    return health;
}

void Collector::setAge(int age) {
    this->age = age;
}

void Collector::setHealth(int health) {
    this->health = health;
}