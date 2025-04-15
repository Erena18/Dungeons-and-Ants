#pragma once
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "MaterialsItem.h"
#include "FoodItem.h"
#include "GarbageManager.h"

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
    void dailyUpdate();

private:
    vector<MaterialItem> materialsItems;
    int amount;
};