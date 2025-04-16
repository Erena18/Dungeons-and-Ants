#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "MaterialsItem.h"
#include "GarbageManager.h"

using namespace std;
using namespace sf;

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

    void drawAllMaterials(RenderWindow& window);

private:
    vector<MaterialItem> materialsItems;
    int amount;
};