#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Zone.h"

using namespace std;

// Пастбищная зона
class PastureZone : public Zone {


public:
    PastureZone(int initialCapacity) : capacity(initialCapacity) {}

    std::string getType() const override { return "Pasture"; }

    void update() override {
        if (capacity > 0 && capacity < 10) {
            ++capacity; // Восстановление вместимости раз в 15-20 дней
            //std::cout << "Pasture zone capacity increased to " << capacity << "." << std::endl;
        }
    }

    void onAntEnter() override {
        if (capacity > 0) {
            --capacity;
            //std::cout << "An ant grazed in the pasture. Remaining capacity: " << capacity << "." << std::endl;
        }
        else {
            //std::cout << "No grazing available in this zone." << std::endl;
        }
    }

private:
    int capacity; // Вместимость корма
};