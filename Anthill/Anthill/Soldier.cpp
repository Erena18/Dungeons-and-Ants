#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Soldier.h"

using namespace std;

void Soldier::Eat(Ant& ant, Food& food)
{
    int foodRequired = 20;
    int hpLossWithoutFood = 15;
    int hpRestoreAfterEating = 30;

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