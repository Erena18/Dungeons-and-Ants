#pragma once

#include "Anthill.h"
#include "Building.h"
#include "Warehouse.h"
#include "Food.h"
#include "FoodItem.h"
#include "Materials.h"
#include "MaterialsItem.h"
#include "GarbageManager.h"
#include "Workshop.h"

#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

class Garbage 
{
public:
    enum class Type 
    {
        RottenFood,
        RottenMaterial,
        Corpse
    };
    Garbage(Type type, int weight);
    Type getType() const;
    int getWeight() const;

private:
    Type type;
    int weight;
};