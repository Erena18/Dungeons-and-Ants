#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Zone.h"

using namespace std;
// Съестная зона
class FoodZone : public Zone 
{

public:
    FoodZone(int initialCapacity) : capacity(initialCapacity) {}

    std::string getType() const override { return "Food"; }

    void update() override 
    {
        if (capacity > 0 && capacity < 10) {
            ++capacity; // Восстановление вместимости раз в 15-20 дней
        }
    }

    void onAntEnter() override 
    {
        if (capacity > 0) {
            --capacity;
            //std::cout << "An ant collected food. Remaining capacity: " << capacity << "." << std::endl;
        }
        else {
            //std::cout << "No food left in this zone." << std::endl;
        }
    }

private:
    int capacity; // Вместимость еды

};