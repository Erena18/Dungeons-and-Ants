#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Materials.h"

using namespace std;

Materials::Materials() {}

void Materials::addMaterial(int amount) 
{
    materialsItems.emplace_back(amount);
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

    for (auto it = materialsItems.begin(); it != materialsItems.end() && amount > 0;) 
    {
        if (!it->isSpoiled()) 
        {
            int itemAmount = it->getAmount();
            int consumeAmount = (itemAmount <= amount) ? itemAmount : amount;

            amountConsumed += consumeAmount;
            amount -= consumeAmount;

            if (itemAmount <= consumeAmount) 
            {
                it = materialsItems.erase(it);
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
    for (const auto& item : materialsItems) 
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
    for (auto it = materialsItems.begin(); it != materialsItems.end();) 
    {
        it->increaseAge();

        if (it->isSpoiled()) 
        {
            GarbageManager::getInstance().addGarbage(Garbage::Type::RottenMaterial, it->getAmount());
            it = materialsItems.erase(it);
        }
        else 
        {
            ++it;
        }
    }
}