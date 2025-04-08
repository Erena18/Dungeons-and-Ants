#pragma once

#include "Anthill.h"
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

class Building 
{
public:
    Building(int capacity, int count, int constructionCost);
    virtual ~Building() {}

    int getCapacity()const;
    int getCount() const;
    int getConstructionCost() const;

    virtual void dailyUpdate() = 0;

protected:
    int capacity;
    int count;
    int constructionCost;
};