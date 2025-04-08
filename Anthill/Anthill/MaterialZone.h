#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Zone.h"

using namespace std;

// Материальная зона
class MaterialZone : public Zone {

public:
    MaterialZone(int initialCapacity) : capacity(initialCapacity) {}

    std::string getType() const override { return "Material"; }

    void update() override {
        if (capacity > 0 && capacity < 10) {
            ++capacity; // Восстановление вместимости раз в 15-20 дней
            //std::cout << "Material zone capacity increased to " << capacity << "." << std::endl;
        }
    }

    void onAntEnter() override {
        if (capacity > 0) {
            --capacity;
            //std::cout << "An ant collected materials. Remaining capacity: " << capacity << "." << std::endl;
        }
        else {
            //std::cout << "No materials left in this zone." << std::endl;
        }
    }

private:
    int capacity; // Вместимость материалов

};