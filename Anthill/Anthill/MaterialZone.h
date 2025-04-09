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
#include "EmptyZone.h"
#include "FoodZone.h"
#include "PastureZone.h"

#include "AntLogic.h"
#include "Dimensions.h"

#include "Informers.h"

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>


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
            ++capacity; // �������������� ����������� ��� � 15-20 ����
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
    int capacity; // ����������� ����������

};