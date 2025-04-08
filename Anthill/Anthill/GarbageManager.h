#pragma once

#include "Anthill.h"
#include "Building.h"
#include "Warehouse.h"
#include "Food.h"
#include "FoodItem.h"
#include "Materials.h"
#include "MaterialsItem.h"
#include "Garbage.h"
#include "Workshop.h"

#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

class GarbageManager {
public:
    static GarbageManager& getInstance();

    void addGarbage(Garbage::Type type, int weight);
    void removeGarbage(int index);

    const std::vector<Garbage>& getGarbageList() const;

private:
    GarbageManager() {}
    std::vector<Garbage> garbageList;
};