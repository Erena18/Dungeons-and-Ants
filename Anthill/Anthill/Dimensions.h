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

#include "AntLogic.h"

#include "Informers.h"

#include <cmath>

class Vec2 {
public:
    Vec2(float x = 0, float y = 0) : x(x), y(y) {}

    float getX() const { return x; }
    float getY() const { return y; }

    void set(float newX, float newY);

    Vec2 add(const Vec2& other) const;

    Vec2 scale(float scalar) const;

private:
    float x;
    float y;
};