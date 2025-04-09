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
#include "Dimensions.h"

#include "Informers.h"

#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

void Child::Eat(Ant& ant, Food& food)
{
    Vec2 nannyPosition = ant.getPosition();
    float distance = sqrt(pow(position.getX() - nannyPosition.getX(), 2) +
        pow(position.getY() - nannyPosition.getY(), 2));
    if (distance >= 5.0f && distance <= 10.0f) 
    {
        int foodRequired = 5;
        int hpLossWithoutFood = 5;
        int hpRestoreAfterEating = 10;

        int consumed = food.consume(foodRequired);
        if (consumed > 0)
        {
            ant.restoreHp(hpRestoreAfterEating);
        }
        else
        {
            ant.loseHp(hpLossWithoutFood);
        }
    }
    else 
    {
        NannyInformer* nannyInformer = getInformer();
        if (nannyInformer)
        {
            nannyInformer->notify(); //вызов няни
        }
    }
}

void Child::Work()
{
	return;
}
