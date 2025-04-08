#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Nanny.h"
#include "Child.h"
#include "Queen.h"
#include "Builder.h"
#include "Cleaner.h"
#include "Soldier.h"
#include "Heardsant.h"
#include "Collector.h"
#include "Informers.h"

#include "Food.h"
#include "FoodItem.h"
#include "Anthill.h"

#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

void Builder::Eat(Ant& ant, Food& food)
{
	int foodRequired = 20;
	int hpLossWithoutFood = 10;
	int hpRestoreAfterEating = 15;

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

void Builder::Work()
{
    Anthill& anthill = Anthill::getInstance();
    int materialsAvailable = anthill.getMaterials().getAmount();
    if (materialsAvailable > 0)
    {
        int repairAmount = min(materialsAvailable, 10); // èñïîëüçóåì äî 10 åäèíèö ìàòåðèàëîâ çà ðàç
        anthill.repair(repairAmount);
    }
    else
    {
        //ÂÛÇÛÂÀÅÒÑß ÈÍÔÎÐÌÅÐ, ÊÎÒÎÐÛÉ ÂÛÇÛÂÀÅÒ ÑÁÎÐÙÈÊÎÂ
        if (informer) 
{
            informer->notify("COLLECTORS WORK");
        }
    }
    Warehouse& warehouse = anthill.getWarehouse();
    if (warehouse.getCapacity() > warehouse.getCount())
    {
        int extensionCost = 50; // Ïðèìåðíàÿ ñòîèìîñòü ðàñøèðåíèÿ íà 50 åäèíèö
        if (materialsAvailable >= extensionCost)
        {
            warehouse.extend(50, extensionCost);
            anthill.getMaterials().use(extensionCost);
        }
        else {        }
    }
}