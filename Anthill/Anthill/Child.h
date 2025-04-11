#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Builder.h"
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

class Child : public Role
{
public:
	Child(Vec2 startPos) : position(startPos) {}

	virtual void Work() override;
	virtual void Eat(Ant& ant, Food& food) override;
	Child(NannyInformer* informer) : informer(informer) {}
	NannyInformer* getInformer() const { return informer; }
	void setInformer(NannyInformer* informer)
	{
		this->informer = informer;
	}
	//здесь ошибка 
	Child(Vec2 startPos) : position(startPos) {}
	Vec2 getPosition() const { return position; }
private:
	NannyInformer* informer;
	Vec2 position;
};