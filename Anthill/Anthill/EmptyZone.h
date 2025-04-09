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
#include "DangerousZone.h"
#include "FoodZone.h"
#include "MaterialZone.h"
#include "PastureZone.h"

#include "AntLogic.h"
#include "Dimensions.h"

#include "Informers.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

class Ant;

using namespace std;

class EmptyZone : public Zone 
{

public:
    std::string getType() const override { return "Empty"; }

    bool isEmpty() const override { return true; }

    void update() override {
        ++daysSinceLastUpdate;
        if (daysSinceLastUpdate >= 50) { //в тз 50 дней написано, поэтому пока 50 дней и будет
            // Зона обновляется и становится одной из трех случайных зон
            //std::cout << "Empty zone has been refreshed!" << std::endl;
            daysSinceLastUpdate = 0;
        }
    }

    void onAntEnter() override {
        //std::cout << "An ant entered an empty zone." << std::endl;

    }

private:
    int daysSinceLastUpdate = 0;
};
