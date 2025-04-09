#pragma once

#include "Role.h"
#include "Ant.h"

#include "Food.h"
#include "FoodItem.h"
#include "Anthill.h"

/*#include "Aphid.h"
#include "Builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collector.h"
#include "Heardsant.h"
#include "Nanny.h"
#include "Soldier.h"

#include "Building.h"

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

#include "Informers.h"*/

#include <iostream>
#include <memory>
#include <vector>
using namespace std;


class Queen : public Role
{
public:
	virtual void Work() override;
	virtual void Eat(Ant& ant, Food& food) override;
	//Queen(Informer* informer) : informer(informer) {}
private:
	//Informer* informer;
};