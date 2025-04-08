#pragma once

#include "Anthill.h"
#include "Building.h"
#include "Warehouse.h"
#include "Food.h"
#include "FoodItem.h"
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

class Materials 
{
public:
    Materials();

    void addMaterial(int amount);
    int consume(int amount);
    int getAmount() const;
    int getTotalAmount() const;
    void use(int amount);
    void dailyUpdate(); // Увеличивает возраст материалов и удаляет испорченные

private:
    vector<MaterialItem> materialItems;
    int amount;
};