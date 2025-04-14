#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Builder.h"

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
        int repairAmount = min(materialsAvailable, 10); // используем до 10 единиц материалов за раз
        anthill.repair(repairAmount);
    }
    else
    {
        CollectorInformer* collectorInformer = getInformer();
        if (collectorInformer)
        {
            collectorInformer->notify(); //вызов сборщиков
        }
    }
    Warehouse& warehouse = anthill.getWarehouse();
    if (warehouse.getCapacity() > warehouse.getCount())
    {
        int extensionCost = 50; // Примерная стоимость расширения на 50 единиц
        if (materialsAvailable >= extensionCost)
        {
            warehouse.extend(50, extensionCost);
            anthill.grow(warehouse.getCapacity() * 0.1f);
            anthill.getMaterials().use(extensionCost);
        }
    }
}