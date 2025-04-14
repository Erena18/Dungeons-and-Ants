#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Zone.h"

class Ant;

using namespace std;

// Опасная зона
class DangerousZone : public Zone {


public:
    DangerousZone(int initialHealth, int maxHealth) : enemyHealth(initialHealth), maxHealth(maxHealth) {}

    std::string getType() const override { return "Dangerous"; }

    void update() override;

    void onAntEnter() override {
        //std::cout << "An ant entered a dangerous zone and died!" << std::endl;
    }

private:
    int enemyHealth;
    int maxHealth;
};