#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "Zone.h"

class Ant;

using namespace std;

class FoodZone : public Zone 
{

public:
    FoodZone(int initialCapacity) : capacity(initialCapacity) {}
    string getType() const override { return "Food"; }

    void update() override 
    {
        if (capacity > 0 && capacity < 10) 
        {
            ++capacity; // Восстановление вместимости раз в 15-20 дней
        }
    }

    void onAntEnter() override 
    {
        if (capacity > 0) 
        {
            --capacity;
        }
        else {   }
    }
private:
    int capacity; // Вместимость еды

};