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

Food::Food() {}

void Food::addFood(int amount) 
{
    FoodItem newItem(amount);
    foodItems.push_back(newItem);
}

int Food::consume(int amount) 
{
    int amountConsumed = 0;

    for (auto it = foodItems.begin(); it != foodItems.end() && amount > 0;) 
    {
        if (!it->isSpoiled()) 
        {
            int itemAmount = it->getAmount();
            int consumeAmount = (itemAmount <= amount) ? itemAmount : amount;

            amountConsumed += consumeAmount;
            amount -= consumeAmount;

            if (itemAmount <= consumeAmount) 
            {
                it = foodItems.erase(it);
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

int Food::getTotalAmount() const 
{
    int total = 0;
    for (const auto& item : foodItems) 
    {
        if (!item.isSpoiled()) 
        {
            total += item.getAmount();
        }
    }
    return total;
}

void Food::dailyUpdate() 
{
    for (auto it = foodItems.begin(); it != foodItems.end();) 
    {
        it->increaseAge();

        if (it->isSpoiled()) 
        {
            GarbageManager::getInstance().addGarbage(Garbage::Type::RottenFood, it->getAmount());
            it = foodItems.erase(it);
        }
        else 
        {
            ++it;
        }
    }
}