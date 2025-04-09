#include "Role.h"
#include "Ant.h"

#include "Food.h"
/*#include "FoodItem.h"
#include "Anthill.h"

#include "Aphid.h"
#include "Builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collector.h"
#include "Heardsant.h"
#include "Nanny.h"
#include "Queen.h"
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
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;


void Queen::Eat(Ant& ant, Food& food) 
{
	int foodRequired = 30;
	int hpLossWithoutFood = 15;
	int hpRestoreAfterEating = 20;

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

void Queen::Work()
{
	Anthill& anthill = Anthill::getInstance();
	if (!anthill.canAddAnt()) 
	{
		return;
	}
	int count = rand() % 11; // Количество родившихся 0-10
	for (int i = 0; i < count && anthill.canAddAnt(); ++i) 
	{
		unique_ptr<Ant> newAnt = make_unique<Ant>(100, 0, make_unique<Child>());
		anthill.addAnt(move(newAnt));
	}
}