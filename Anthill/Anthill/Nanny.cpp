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

void Nanny::Eat(Ant& ant, Food& food)
{
	int foodRequired = 7;
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

void Nanny::Work() 
{
    vector<Child*> children;
    for (Child* child : children) 
    {
        Vec2 childPosition = child->getPosition();
        float distance = sqrt(pow(position.getX() - childPosition.getX(), 2) +
            pow(position.getY() - childPosition.getY(), 2));
        if (distance > 10.0f) 
        {
            targetPosition = childPosition;
            isMoving = true;
            return;
        }
    }
}

void Nanny::update(float dt) 
{
    if (isMoving) 
    {
        Vec2 direction = Vec2(targetPosition.getX() - position.getX(),
            targetPosition.getY() - position.getY());
        float length = sqrt(direction.getX() * direction.getX() + direction.getY() * direction.getY());
        if (length > 0) 
        {
            direction = direction.scale(1.0f / length);
            position = position.add(direction.scale(speed * dt));
            float newDistance = sqrt(pow(position.getX() - targetPosition.getX(), 2) +
                pow(position.getY() - targetPosition.getY(), 2));
            if (newDistance <= 10.0f) 
            { 
                isMoving = false;
            }
        }
    }
}