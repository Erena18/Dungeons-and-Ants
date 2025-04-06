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

    void dailyUpdate();

private:
    Anthill();

    void removeDeadAnts();

    std::vector<std::unique_ptr<Ant>> ants;
    Food food;
    Materials materials;
    InformerCollector informerCollector;
    InformerCleaner informerCleaner;
};

#endif // ANTHILL_H