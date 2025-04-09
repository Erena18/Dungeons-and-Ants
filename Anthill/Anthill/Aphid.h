#pragma once

#include "Role.h"
#include "Ant.h"
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
#include <memory>
#include <vector>
using namespace std;

class Aphid
{
public:
	Aphid();

	void growthAphid(int& amountFood);
	void dieAphid(int& amountFood);
	void loseHpAphid(int damageHp, int& amountFood);
	void restoreHpAphid(int point);
	void Eat(Food& food);
private:
	int hpAphid, ageAphid;

};