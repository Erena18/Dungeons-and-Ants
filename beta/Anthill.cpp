#include "Anthill.h"
#include "Collector.h"
#include "Cleaner.h"

#include <iostream>
#include <algorithm>
#include <cstdlib>

Anthill::Anthill(const std::string& name)
    : name(name), populationCapacity(12), population(0), durability(200), materialSupply(500) {
    // Initialize warehouses
    for (int i = 0; i < 2; ++i) {
        Warehouse warehouse = { 300, 0 }; // No initial food
        warehouses.push_back(warehouse);
    }
    centralWarehouse = { 400, 0 }; // No initial food
}

Anthill::~Anthill() {
    for (Collector* collector : collectors) {
        delete collector;
    }
    for (Cleaner* cleaner : cleaners) {
        delete cleaner;
    }
}

void Anthill::addCollector(Collector* collector) {
    if (population < populationCapacity) {
        collectors.push_back(collector);
        population++;
    }
    else {
        std::cout << "The anthill is full! Cannot add more collectors.\n";
    }
}

void Anthill::removeCollector(Collector* collector) {
    auto it = std::find(collectors.begin(), collectors.end(), collector);
    if (it != collectors.end()) {
        collectors.erase(it);
        population--;
    }
}

void Anthill::addCleaner(Cleaner* cleaner) {
    if (population < populationCapacity) {
        cleaners.push_back(cleaner);
        population++;
    }
    else {
        std::cout << "The anthill is full! Cannot add more cleaners.\n";
    }
}

void Anthill::removeCleaner(Cleaner* cleaner) {
    auto it = std::find(cleaners.begin(), cleaners.end(), cleaner);
    if (it != cleaners.end()) {
        cleaners.erase(it);
        population--;
    }
}

void Anthill::promoteCollectorToCleaner(Collector* collector) {
    std::cout << "A collector has aged and becomes a cleaner.\n";
    Cleaner* cleaner = new Cleaner(this);
    addCleaner(cleaner);
    removeCollector(collector);
    delete collector;
}

void Anthill::dailyUpdate() {
    // Daily updates for the anthill

    // Update collectors
    for (size_t i = 0; i < collectors.size(); ) {
        Collector* collector = collectors[i];
        collector->dailyUpdate();
        if (collector->getHealth() <= 0) {
            delete collector;
            collectors.erase(collectors.begin() + i);
            population--;
        }
        else if (collector->getAge() > 79) {
            promoteCollectorToCleaner(collector);
        }
        else {
            ++i;
        }
    }

    // Update cleaners
    for (size_t i = 0; i < cleaners.size(); ) {
        Cleaner* cleaner = cleaners[i];
        cleaner->dailyUpdate();
        if (cleaner->getHealth() <= 0 || cleaner->getAge() > 100) {
            delete cleaner;
            cleaners.erase(cleaners.begin() + i);
            population--;
        }
        else {
            ++i;
        }
    }

    // Natural decay of the anthill
    int decay = 1 + rand() % 2;
    durability -= decay;
    if (durability < 0) durability = 0;

    // Increase capacity as durability increases
    if (durability % 25 == 0 && durability != 0) {
        populationCapacity += 5;
        std::cout << "The anthill's durability increased, adding 5 more living spaces.\n";
    }

    // Output current status
    std::cout << "Anthill status:\n";
    std::cout << "Population: " << population << "/" << populationCapacity << "\n";
    std::cout << "Durability: " << durability << "\n";
    std::cout << "Material supply: " << materialSupply << "\n";
    std::cout << "Total food supply: " << getTotalFoodSupply() << "\n";
    std::cout << "Central warehouse load: " << centralWarehouse.currentLoad << "/" << centralWarehouse.capacity << "\n";
    for (size_t i = 0; i < warehouses.size(); ++i) {
        std::cout << "Warehouse " << i + 1 << ": " << warehouses[i].currentLoad << "/" << warehouses[i].capacity << "\n";
    }
}

void Anthill::consumeFood(int amount) {
    int remaining = amount;
    // Consume food from warehouses
    for (auto& warehouse : warehouses) {
        if (warehouse.currentLoad > 0) {
            int toConsume = std::min(warehouse.currentLoad, remaining);
            warehouse.currentLoad -= toConsume;
            remaining -= toConsume;
            if (remaining == 0) return;
        }
    }
    // Consume food from central warehouse
    if (remaining > 0 && centralWarehouse.currentLoad > 0) {
        int toConsume = std::min(centralWarehouse.currentLoad, remaining);
        centralWarehouse.currentLoad -= toConsume;
        remaining -= toConsume;
    }
    // If not enough food
    if (remaining > 0) {
        std::cout << "Not enough food! " << remaining << " units could not be consumed.\n";
    }
}

void Anthill::addFoodSupply(int amount) {
    int remaining = amount;
    // Store food in warehouses
    for (auto& warehouse : warehouses) {
        int availableSpace = warehouse.capacity - warehouse.currentLoad;
        if (availableSpace > 0) {
            int toStore = std::min(remaining, availableSpace);
            warehouse.currentLoad += toStore;
            remaining -= toStore;
            if (remaining == 0) break;
        }
    }

    // Store food in central warehouse
    if (remaining > 0) {
        int availableSpace = centralWarehouse.capacity - centralWarehouse.currentLoad;
        if (availableSpace > 0) {
            int toStore = std::min(remaining, availableSpace);
            centralWarehouse.currentLoad += toStore;
            remaining -= toStore;
        }
    }

    // If no space left
    if (remaining > 0) {
        std::cout << "Failed to store " << remaining << " units of food due to lack of space.\n";
    }
}

void Anthill::addGarbage(int amount) {
    std::cout << amount << " units of garbage added to the dump.\n";
}

void Anthill::addMaterials(int amount) {
    materialSupply += amount;
}

void Anthill::useMaterials(int amount) {
    if (materialSupply >= amount) {
        materialSupply -= amount;
    }
    else {
        std::cout << "Not enough materials!\n";
    }
}

void Anthill::buildWarehouse() {
    if (materialSupply >= 100) {
        useMaterials(100);
        Warehouse warehouse = { 300, 0 };
        warehouses.push_back(warehouse);
        std::cout << "A new warehouse has been built. You now have " << warehouses.size() << " warehouse(s).\n";
    }
    else {
        std::cout << "Not enough materials to build a warehouse!\n";
    }
}

void Anthill::expandCentralWarehouse() {
    int cost = 125 + rand() % 26;
    if (materialSupply >= cost) {
        useMaterials(cost);
        centralWarehouse.capacity += 50;
        std::cout << "Central warehouse expanded. New capacity: " << centralWarehouse.capacity << "\n";
    }
    else {
        std::cout << "Not enough materials to expand the central warehouse!\n";
    }
}

void Anthill::alertWarriors() {
    std::cout << "Warriors have been alerted to danger!\n";
}

void Anthill::callForCollectorHelp() {
    std::cout << "Collectors are calling for help!\n";
    // Additional logic can be implemented
}

void Anthill::callForCleanerHelp() {
    std::cout << "Cleaners are calling for help!\n";
    // Additional logic can be implemented
}

int Anthill::getPopulation() const {
    return population;
}

int Anthill::getPopulationCapacity() const {
    return populationCapacity;
}

int Anthill::getDurability() const {
    return durability;
}

int Anthill::getMaterialSupply() const {
    return materialSupply;
}

int Anthill::getTotalFoodSupply() const {
    int totalFood = centralWarehouse.currentLoad;
    for (const auto& warehouse : warehouses) {
        totalFood += warehouse.currentLoad;
    }
    return totalFood;
}

void Anthill::increaseDurability(int amount) {
    durability += amount;
}

void Anthill::decreaseDurability(int amount) {
    durability -= amount;
    if (durability < 0) durability = 0;
}