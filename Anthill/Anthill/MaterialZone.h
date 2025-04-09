#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Zone.h"

using namespace std;


class MaterialZone : public Zone 
{

public:
    MaterialZone(int initialCapacity) : capacity(initialCapacity) {}

    string getType() const override { return "Material"; }

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
        else { }
    }
private:
    int capacity; // Вместимость материалов

};