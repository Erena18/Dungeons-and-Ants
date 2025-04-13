#pragma once

#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <ctime>

using namespace sf;
using namespace std;

#include "extraFiles.h"
#include "Engine.h"

#include "Ant.h"
#include "Anthill.h"
#include "Building.h"

/*#include "Role.h"
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

#include "Zone.h"
#include "DangerousZone.h"
#include "EmptyZone.h"
#include "FoodZone.h"
#include "MaterialZone.h"
#include "PastureZone.h"

#include "Informers.h"
*/

class Ant;
class Anthill;

class Warehouse : public Building 
{
public:
    //Warehouse();
    Warehouse(GameDataRef data);
    ~Warehouse();
    void drawnWarehouse();
    void spawnWarehouse(float x, float y);
    void dailyUpdate() override;
    void extend(int additionalCapacity, int cost);

private:
    //int extensionCostPer50Units;
    GameDataRef _data;
    CircleShape _nestCircle;
    float radius;
};