#pragma once
#include "Anthill.h"
#include "Building.h"
#include "Warehouse.h"
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

class Food 
{
public:
    Food();

    void addFood(int amount);
    int consume(int amount);

    int getTotalAmount() const;
    void dailyUpdate(); // Увеличивает возраст еды и удаляет испорченную

private:
    vector<FoodItem> foodItems;
};
