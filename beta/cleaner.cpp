#include "Cleaner.h"
#include "Anthill.h"
#include <iostream>
#include <cstdlib>

Cleaner::Cleaner(Anthill* anthill, int age, int health)
    : anthill(anthill), age(age), health(health), cargoCapacity(2), cargo(0), state("Idle") {
    maxDistance = 15 + (health % 21);
}

Cleaner::~Cleaner() {
    // Destructor
}

void Cleaner::dailyUpdate() {
    // Increase age
    age++;

    // Work first
    work();

    // Health loss after working
    int healthLoss = rand() % 3 + 1;
    health -= healthLoss;

    // Update maxDistance
    maxDistance = 15 + (health % 21);

    // Check for death after working
    if (health <= 0) {
        std::cout << "A cleaner has died of exhaustion.\n";
        return;
    }

    if (health <= 5) {
        std::cout << "Cleaner is mortally weak and goes away to die.\n";
        health = 0; // Mark as dead
        return;
    }
}

void Cleaner::work() {
    std::cout << "Cleaner starts cleaning the area.\n";

    int foodConsumption = 10 + rand() % 6;
    anthill->consumeFood(foodConsumption);

    int foundGarbage = rand() % 6;

    if (foundGarbage > 0) {
        if (foundGarbage <= cargoCapacity) {
            cargo += foundGarbage;
            std::cout << "Cleaner collected " << foundGarbage << " units of garbage.\n";
            anthill->addGarbage(cargo);
            cargo = 0;
        }
        else {
            cargo += cargoCapacity;
            std::cout << "Cleaner found a lot of garbage and calls for help.\n";
            anthill->addGarbage(cargo);
            cargo = 0;
            anthill->callForCleanerHelp();
        }
    }
    //THIS IS MY SHIZA SO THAT PROBABLY SHOULD NOT BE ADDED IDK
    int chance = rand() % 100;
    if (chance < 50) {
        std::cout << "Cleaner became a thief on foreign territory!\n";
        // Дополнительная логика для вора
    }
  

    chance = rand() % 100;
    if (chance < 20) {
        std::cout << "Cleaner entered a dangerous zone and perished!\n";
        health = 0; // Mark as dead
    }
}
// END OF THE SHIZA
int Cleaner::getAge() const {
    return age;
}

int Cleaner::getHealth() const {
    return health;
}

void Cleaner::setAge(int age) {
    this->age = age;
}

void Cleaner::setHealth(int health) {
    this->health = health;
}