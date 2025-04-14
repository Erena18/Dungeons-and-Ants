#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "Zone.h"

using namespace std;

// Пастбищная зона
class PastureZone : public Zone 
{
public:
    PastureZone(int initialCapacity) : capacity(initialCapacity) {}

    string getType() const override { return "Pasture"; }

    void update() override 
    {
        if (capacity > 0 && capacity < 10) 
        {
            ++capacity; // Восстановление вместимости ОТКАЛИБРОВАТЬ
        }
    }
    void onAntEnter() override
    {
        if (capacity > 0) 
        {
            --capacity;
        }
        else 
        {        }
    }

private:
    int capacity; // Вместимость корма
};