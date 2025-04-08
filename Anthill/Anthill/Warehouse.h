#pragma once
#include "Anthill.h"
#include "Building.h"
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

class Warehouse : public Building 
{
public:
    Warehouse();
    void dailyUpdate() override;
    void extend(int additionalCapacity, int cost);

private:
    int extensionCostPer50Units;
};