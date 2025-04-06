// Anthill.h
#ifndef ANTHILL_H
#define ANTHILL_H

#include <vector>
#include <memory>
#include "Ant.h"
#include "Food.h"
#include "Materials.h"
#include "InformerCollector.h"
#include "InformerCleaner.h"
#include "Workshop.h"
#include "Warehouse.h"
#include "CentralWarehouse.h"

class Anthill {
public:
    static Anthill& getInstance();


    void addAnt(std::unique_ptr<Ant> ant);
    void addFood(int amount);
    void addMaterials(int amount);
    Food& getFood();
    Materials& getMaterials();

    InformerCollector& getInformerCollector();
    InformerCleaner& getInformerCleaner();
    Workshop& getWorkshop();
    Warehouse& getWarehouse();
    CentralWarehouse& getCentralWarehouse();
    void repair(int amount);
    void receiveDamage(int amount);

    bool canAddAnt() const;

    void dailyUpdate();

private:
    Anthill();



    std::vector<std::unique_ptr<Ant>> ants;
    Food food;
    Materials materials;
    InformerCollector informerCollector;
    InformerCleaner informerCleaner;
    int maxPopulation;
    int durability; // Прочность
    int naturalDecayMin;
    int naturalDecayMax;

    Workshop workshop;
    Warehouse warehouse;
    CentralWarehouse centralWarehouse;
    void removeDeadAnts();
};
#endif // ANTHILL_H