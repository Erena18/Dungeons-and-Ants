#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collector.h"
#include "Heardsant.h"
#include "Nanny.h"
#include "Queen.h"
#include "Soldier.h"

#include "Anthill.h"
#include "Building.h"
#include "Food.h"
#include "FoodItem.h"
#include "Garbage.h"
#include "GarbageManager.h"
#include "Materials.h"
#include "MaterialsItem.h"
#include "Warehouse.h"

#include "Zone.h"
#include "EmptyZone.h"
#include "FoodZone.h"
#include "MaterialZone.h"
#include "PastureZone.h"

#include "AntLogic.h"
#include "Dimensions.h"

#include "Informers.h"

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>

class Ant;

using namespace std;

// Опасная зона
class DangerousZone : public Zone {


public:
    DangerousZone(int initialHealth, int maxHealth) : enemyHealth(initialHealth), maxHealth(maxHealth) {}

    std::string getType() const override { return "Dangerous"; }

    void update() override {
        static int daysSinceLastUpdate = 0;
        ++daysSinceLastUpdate;

        if (daysSinceLastUpdate % 5 == 0) {
            enemyHealth -= 10; // Уменьшение здоровья врага
            //std::cout << "Enemy health decreased to " << enemyHealth << "." << std::endl;

            if (enemyHealth <= 0) {
                //std::cout << "Enemy is critically weak. Expanding dangerous zone!" << std::endl;
                // Расширение опасной зоны
            }
        }

        if (enemyHealth >= maxHealth) {
            //std::cout << "Enemy reached max health. Expanding dangerous zone!" << std::endl;
            // Расширение опасной зоны
        }
    }

    void onAntEnter() override {
        //std::cout << "An ant entered a dangerous zone and died!" << std::endl;
    }

private:
    int enemyHealth;
    int maxHealth;
};