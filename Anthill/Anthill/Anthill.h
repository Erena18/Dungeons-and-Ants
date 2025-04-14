#pragma once
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Building.h"
#include "Food.h"
#include "FoodItem.h"
#include "Garbage.h"
#include "GarbageManager.h"
#include "Materials.h"
#include "MaterialsItem.h"
#include "Warehouse.h"

using namespace std;


class Anthill 
{
public:
    static Anthill& getInstance();


    void addAnt(std::unique_ptr<Ant> ant);
    void addFood(int amount);
    void addMaterials(int amount);
    Food& getFood();
    Materials& getMaterials();

    Warehouse& getWarehouse();
    void repair(int amount);
    void receiveDamage(int amount);

    bool canAddAnt() const;

    void dailyUpdate();

private:
    Anthill();
    vector<unique_ptr<Ant>> ants;
    Food food;
    Materials materials;
    int maxPopulation;
    int durability;
    int naturalDecayMin;
    int naturalDecayMax;

    Warehouse warehouse;
    void removeDeadAnts();
};