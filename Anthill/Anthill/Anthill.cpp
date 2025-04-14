#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Anthill.h"

using namespace std;

Anthill::Anthill(GameDataRef data) :_data(data)
{
    updateRadius();
    _nestCircle.setFillColor(Color(139, 69, 19));
}

Anthill& Anthill::getInstance()
{
    static Anthill instance;
    return instance;
}

void Anthill::drawAnthill()
{
    _data->window.draw(_nestCircle);
}

void Anthill::spawnAnthill(float x, float y)
{
    _nestCircle.setPosition(x, y);
    _nestCircle.setOrigin(_nestCircle.getRadius(), _nestCircle.getRadius());
}

void Anthill::grow(float amount)
{
    radius += amount;
    _nestCircle.setRadius(radius);
    _nestCircle.setOrigin(radius, radius);
}

void Anthill::setCapacity(int newCapacity)
{
    curCapacity = newCapacity;
    updateRadius();
}

//ѕоправь данные
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

/*Workshop& Anthill::getWorkshop()
{
    return workshop;
}*/

Warehouse& Anthill::getWarehouse() 
{
    return warehouse;
}

void Anthill::repair(int amount) 
{
    // »спользуем материалы дл€ ремонта
    int materialsAvailable = materials.getAmount();
    int materialsToUse = min(amount, materialsAvailable);

    if (materialsToUse > 0) 
    {
        materials.use(materialsToUse);
        durability += materialsToUse;

        // «а каждые  25 единиц увеличени€ прочности  5 мест дл€ жизни
        maxPopulation = 12 + ((durability - 200) / 25) * 5;
    }
}

void Anthill::receiveDamage(int amount) 
{
    durability -= amount;
    if (durability < 0) 
    {
        durability = 0;
        // ќбработка ситуации, когда муравейник полностью разрушен
    }
    // ќбновл€ем максимальную вместимость
    maxPopulation = 12 + ((durability - 200) / 25) * 5;
}

bool Anthill::canAddAnt() const 
{
    return static_cast<int>(ants.size()) < maxPopulation;
}

void Anthill::dailyUpdate() 
{
    // ≈стественное разрушение
    int decay = naturalDecayMin + rand() % (naturalDecayMax - naturalDecayMin + 1);
    receiveDamage(decay);
    //ѕќѕ–ј¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬№
    for (auto& ant : ants) 
    {
        ant->growth();
        ant->Work();
        ant->Eat(food);
    }

    removeDeadAnts();
    // ќбновл€ем постройки
    warehouse.dailyUpdate();
    food.dailyUpdate();
    materials.dailyUpdate();

    // ≈сли мусора много, отправл€ем уведомление уборщикам
    if (GarbageManager::getInstance().getGarbageList().size() > 10) 
    {
        CleanerInformer* cleanerInformer = getInformer();
        if (cleanerInformer)
        {
            cleanerInformer->notify();
        }
    }
}

void Anthill::updateRadius()
{
    float radius = curCapacity * radiusPerUnit;
    _nestCircle.setRadius(radius);
    _nestCircle.setOrigin(radius, radius);
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