#pragma once
#include "GameData.h"
//#include "Engine.h"
#include "extraFiles.h"

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Ant.h"
#include "Building.h"
#include "Food.h"
#include "FoodItem.h"
#include "Garbage.h"
#include "GarbageManager.h"
#include "Informers.h"
#include "Materials.h"
#include "MaterialsItem.h"
#include "Warehouse.h"


using namespace std;
using namespace sf;

class Anthill 
{
public:
    Anthill(GameDataRef data);
    static Anthill& getInstance(GameDataRef data);

    vector<unique_ptr<Ant>>& getAnts() { return ants; }

    void drawAnthill();
    void drawAllAnts(RenderWindow& window);
    void spawnAnthill(float x, float y);
    void grow(float amount);
    void setCapacity(int newCapasity);
   

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

    //Anthill(CleanerInformer* informer) : informer(informer) {}
    CleanerInformer* getInformer() const { return informer; }
    void setInformer(CleanerInformer* informer)
    {
        this->informer = informer;
    }
private:
    //Anthill();
    GameDataRef _data;
    CleanerInformer* informer = nullptr;
    vector<unique_ptr<Ant>> ants;
    Food food;
    Materials materials;
    Warehouse warehouse;

    int maxPopulation;
    int durability;
    int naturalDecayMin;
    int naturalDecayMax;

    CircleShape _nestCircle;
    int curCapacity = 100;
    const float radiusPerUnit = 0.1f;
    float radius;
    void updateRadius();
    void removeDeadAnts();
};