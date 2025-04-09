#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collector.h"
#include "Heardsant.h"
#include "Nanny.h"
#include "Queen.h"
#include "Soldier.h"

#include "Anthill.h"
#include "Building.h"
#include "Food.h"
#include "FoodItem.h"
#include "Garbage.h"
#include "GarbageManager.h"
#include "Materials.h"
#include "MaterialsItem.h"
#include "Warehouse.h"

#include "Zone.h"
#include "DangerousZone.h"
#include "EmptyZone.h"
#include "FoodZone.h"
#include "MaterialZone.h"
#include "PastureZone.h"

#include "AntLogic.h"
#include "Dimensions.h"

#include "Informers.h"


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

    //Workshop& getWorkshop();
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

    //Workshop workshop;
    Warehouse warehouse;
    void removeDeadAnts();
};