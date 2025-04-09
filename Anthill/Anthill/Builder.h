#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
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


class Builder : public Role
{
public:
	virtual void Work() override;
	virtual void Eat(Ant& ant, Food& food) override;
	Builder(CollectorInformer* informer) : informer(informer) {}
	CollectorInformer* getInformer() const { return informer; }
	void setInformer(CollectorInformer* informer) 
	{
		this->informer = informer;
	}
private:
	CollectorInformer* informer;
};