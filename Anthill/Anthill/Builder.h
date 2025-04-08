#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Nanny.h"
#include "Child.h"
#include "Queen.h"
#include "Cleaner.h"
#include "Soldier.h"
#include "Heardsant.h"
#include "Collector.h"
#include "Informers.h"

#include "Food.h"
#include "FoodItem.h"
#include "Anthill.h"

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Builder : public Role
{
public:
	virtual void Work() override;
	virtual void Eat(Ant& ant, Food& food) override;
private:
	Informer* informer;
};