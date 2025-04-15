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
#include "MaterialZone.h"
#include "PastureZone.h"

#include "Dimensions.h"

#include "Informers.h"

#include <cstdlib>

class AntLogic 
{
public:
    AntLogic(Vec2 startPos, float speed = 50.0f, float maxDist = 400.0f)
        : position(startPos), initPosition(startPos), speed(speed),
        maxDistance(maxDist), kudaSobralsya(true) {
        velocity = getRandomDirection();
    }

    void update(float dt, int width, int height);

    Vec2 getPosition() const { return position; }
    Vec2 getVelocity() const { return velocity; }

private:
    Vec2 position;      //current position
    Vec2 initPosition;      //start (nest)
    Vec2 velocity;      //direction
    float speed;        //speed
    float maxDistance;
    bool kudaSobralsya;

    Vec2 getRandomDirection();
};