#pragma once
#include "Anthill.h"
#include "Building.h"
#include "Warehouse.h"
#include "Food.h"
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

class FoodItem 
{
public:
    FoodItem(int amount);

    int getAmount() const;
    int getAge() const;

    void increaseAge();
    bool isSpoiled() const;
    void reduceAmount(int amountToReduce);

private:
    int amount;
    int age; 
};