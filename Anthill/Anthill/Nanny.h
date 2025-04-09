#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collector.h"
#include "Heardsant.h"
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
#include <memory>
#include <vector>
using namespace std;

class Nanny : public Role
{
public:
	Nanny(Vec2 startPos, float speed = 50.0f)
		: position(startPos), speed(speed), 
		targetPosition(startPos), isMoving(false) {}

	Vec2 getPosition() const { return position; }
	virtual void Work() override;
	virtual void Eat(Ant& ant, Food& food) override;

	void update(float dt);
private:
	Vec2 position;
	Vec2 targetPosition;
	float speed;
	bool isMoving;
};