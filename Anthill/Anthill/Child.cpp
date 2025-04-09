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

#include "Dimensions.h"
#include "AntLogic.h"

#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

void Child::Eat(Ant& ant, Food& food)
{
    Vec2 nannyPosition = ant.getPosition();
    float distance = sqrt(pow(position.getX() - nannyPosition.getX(), 2) +
        pow(position.getY() - nannyPosition.getY(), 2));
    if (distance >= 5.0f && distance <= 10.0f) 
    {
        int foodRequired = 5;
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
    else 
    {
        NannyInformer* nannyInformer = getInformer();
        if (nannyInformer)
        {
            nannyInformer->notify(); //вызов няни
        }
    }
}

void Child::Work()
{
	return;
}
