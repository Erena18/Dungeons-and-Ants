#include "Anthill.h"
#include "Building.h"
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

Materials::Materials() {}

void Materials::addMaterial(int amount) 
{
    materialItems.emplace_back(amount);
}
void Materials::use(int amount) 
{
    if (this->amount >= amount) 
    {
        this->amount -= amount;
    }
    else 
    {
        this->amount = 0;
    }
}
int Materials::getAmount() const 
{
    return amount;
}

int Materials::consume(int amount) 
{
    int amountConsumed = 0;

    for (auto it = materialItems.begin(); it != materialItems.end() && amount > 0;) 
    {
        if (!it->isSpoiled()) 
        {
            int itemAmount = it->getAmount();
            int consumeAmount = (itemAmount <= amount) ? itemAmount : amount;

            amountConsumed += consumeAmount;
            amount -= consumeAmount;

            if (itemAmount <= consumeAmount) 
            {
                it = materialItems.erase(it);
            }
            else 
            {
                it->reduceAmount(consumeAmount);
                ++it;
            }
        }
        else 
        {
            ++it;
        }
    }
    return amountConsumed;
}

int Materials::getTotalAmount() const 
{
    int total = 0;
    for (const auto& item : materialItems) 
    {
        if (!item.isSpoiled()) 
        {
            total += item.getAmount();
        }
    }
    return total;
}

void Materials::dailyUpdate() 
{
    for (auto it = materialItems.begin(); it != materialItems.end();) 
    {
        it->increaseAge();

        if (it->isSpoiled()) 
        {
            GarbageManager::getInstance().addGarbage(Garbage::Type::RottenMaterial, it->getAmount());
            it = materialItems.erase(it);
        }
        else 
        {
            ++it;
        }
    }
}