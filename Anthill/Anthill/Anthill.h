#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Nanny.h"
#include "Child.h"
#include "Queen.h"
#include "Builder.h"
#include "Cleaner.h"
#include "Soldier.h"
#include "Heardsant.h"
#include "Collector.h"

#include "Building.h"
#include "Warehouse.h"
#include "Food.h"
#include "FoodItem.h"
#include "Materials.h"
#include "MaterialsItem.h"
#include "Garbage.h"
#include "GarbageManager.h"
#include "Workshop.h"


#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

/*#include <vector>
#include <memory>
#include "Ant.h"
#include "Food.h"
#include "Materials.h"
#include "InformerCollector.h"
#include "InformerCleaner.h"
#include "Workshop.h"
#include "Warehouse.h"
#include "CentralWarehouse.h"*/

class Anthill 
{
public:
    static Anthill& getInstance();


    void addAnt(std::unique_ptr<Ant> ant);
    void addFood(int amount);
    void addMaterials(int amount);
    Food& getFood();
    Materials& getMaterials();

    //InformerCollector& getInformerCollector();
    //InformerCleaner& getInformerCleaner();
    Workshop& getWorkshop();
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
    //InformerCollector informerCollector;
    //InformerCleaner informerCleaner;
    int maxPopulation;
    int durability;
    int naturalDecayMin;
    int naturalDecayMax;

    Workshop workshop;
    Warehouse warehouse;
    void removeDeadAnts();
};