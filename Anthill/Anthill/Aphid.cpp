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

Aphid::Aphid() : hpAphid(20), ageAphid(0) {}

void Aphid::growthAphid(int& amountFood)
{
	ageAphid++;
	if ((hpAphid <= 0) || (ageAphid > 10))
	{
		dieAphid(amountFood);
	}
}

void Aphid::dieAphid(int& amountFood)
{
	//здесь должна быть реализация, что тля умерла внутри муравейника 
	amountFood++;
	//если тля умерла на улице, она становится МУСОРОМ

	//новая рождается в муравейнике в любом случае
	auto newAphid = make_unique<Aphid>();
}

void Aphid::loseHpAphid(int damageHp, int& amountFood)
{
	hpAphid -= damageHp;
	if (hpAphid < 0)
	{
		//int countFood = getAmountFood();
		dieAphid(amountFood);
	}
}

void Aphid::restoreHpAphid(int point)
{
	hpAphid += point;
	if (hpAphid > 20)
	{
		hpAphid = 20;
	}
}

void Aphid::Eat(Food& food)
{
	Zone* currentZone =
		ZoneManager::getInstance().getCurrentZone(*this); //ОШИБКА 
	PastureZone* pasture = dynamic_cast<PastureZone*>(currentZone);
	if (pasture) 
	{
		if (!pasture->isEmpty()) 
		{
			restoreHpAphid(1);
			pasture->onAntEnter();
		}
	}
}