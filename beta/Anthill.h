#ifndef ANTHILL_H
#define ANTHILL_H

#include <string>
#include <vector>

// Forward declarations of Collector and Cleaner classes
class Collector;
class Cleaner;

class Anthill {
private:
    std::string name;
    int populationCapacity; // Maximum population
    int population;
    int durability; // Anthill durability
    int materialSupply;

    // Parameters for warehouses
    struct Warehouse {
        int capacity;     // Capacity
        int currentLoad;  // Current load of food
    };

    std::vector<Warehouse> warehouses;        // Regular warehouses
    Warehouse centralWarehouse;               // Central warehouse

    std::vector<Collector*> collectors;
    std::vector<Cleaner*> cleaners;

public:
    Anthill(const std::string& name);
    ~Anthill();

    // Methods to manage ants
    void addCollector(Collector* collector);
    void removeCollector(Collector* collector);
    void addCleaner(Cleaner* cleaner);
    void removeCleaner(Cleaner* cleaner);

    void promoteCollectorToCleaner(Collector* collector);

    // Daily update
    void dailyUpdate();

    // Resource management
    void consumeFood(int amount);
    void addFoodSupply(int amount);
    void addGarbage(int amount);
    void addMaterials(int amount);
    void useMaterials(int amount);

    // Warehouse management
    void buildWarehouse();
    bool storeInWarehouse(int amount);
    bool storeInCentralWarehouse(int amount);
    void expandCentralWarehouse();

    // Events
    void alertWarriors();
    void callForCollectorHelp();
    void callForCleanerHelp();

    // Getters
    int getPopulation() const;
    int getPopulationCapacity() const;
    int getDurability() const;
    int getMaterialSupply() const;
    int getTotalFoodSupply() const;

    void increaseDurability(int amount);
    void decreaseDurability(int amount);
};

#endif // ANTHILL_H