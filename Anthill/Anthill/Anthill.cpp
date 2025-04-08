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

#include "Anthill.h"
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

Anthill& Anthill::getInstance() 
{
    static Anthill instance;
    return instance;
}

//Поправь данные
Anthill::Anthill() : maxPopulation(500), durability(200), naturalDecayMin(1), naturalDecayMax(2) {}

void Anthill::addAnt(unique_ptr<Ant> ant) 
{
    ants.push_back(move(ant));
}

void Anthill::addFood(int amount) 
{
    food.addFood(amount);
}

void Anthill::addMaterials(int amount) 
{
    materials.addMaterial(amount);
}

Food& Anthill::getFood() 
{
    return food;
}

Materials& Anthill::getMaterials() 
{
    return materials;
}

InformerCollector& Anthill::getInformerCollector() 
{
    return informerCollector;
}

InformerCleaner& Anthill::getInformerCleaner() 
{
    return informerCleaner;
}

Workshop& Anthill::getWorkshop() 
{
    return workshop;
}

Warehouse& Anthill::getWarehouse() 
{
    return warehouse;
}

void Anthill::repair(int amount) 
{
    // Используем материалы для ремонта
    int materialsAvailable = materials.getAmount();
    int materialsToUse = min(amount, materialsAvailable);

    if (materialsToUse > 0) 
    {
        materials.use(materialsToUse);
        durability += materialsToUse;

        // За каждые  25 единиц увеличения прочности  5 мест для жизни
        maxPopulation = 12 + ((durability - 200) / 25) * 5;
    }
}

void Anthill::receiveDamage(int amount) 
{
    durability -= amount;
    if (durability < 0) 
    {
        durability = 0;
        // Обработка ситуации, когда муравейник полностью разрушен
    }
    // Обновляем максимальную вместимость
    maxPopulation = 12 + ((durability - 200) / 25) * 5;
}

bool Anthill::canAddAnt() const 
{
    return static_cast<int>(ants.size()) < maxPopulation;
}

void Anthill::dailyUpdate() 
{
    // Естественное разрушение
    int decay = naturalDecayMin + rand() % (naturalDecayMax - naturalDecayMin + 1);
    receiveDamage(decay);
    for (auto& ant : ants) 
    {
        ant->growth();
        ant->Work();
        ant->Eat(food);
    }

    removeDeadAnts();
    // Обновляем постройки
    workshop.dailyUpdate();
    warehouse.dailyUpdate();
    centralWarehouse.dailyUpdate();
    food.dailyUpdate();
    materials.dailyUpdate();

    // Если мусора много, отправляем уведомление уборщикам
    if (GarbageManager::getInstance().getGarbageList().size() > 10) 
    {
        informerCleaner.notify("Garbage accumulated, need cleaning!");
    }
}

void Anthill::removeDeadAnts() 
{
    for (auto it = ants.begin(); it != ants.end();) 
    {
        if (!(*it)->isAlive()) 
        {
            GarbageManager::getInstance().addGarbage(Garbage::Type::Corpse, 1);
            it = ants.erase(it);
        }
        else 
        {
            ++it;
        }
    }
}