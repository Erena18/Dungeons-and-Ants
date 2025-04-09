#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Nanny.h"
#include "Child.h"
#include "Builder.h"
#include "Cleaner.h"
#include "Soldier.h"
#include "Heardsant.h"
#include "Collector.h"

#include "Food.h"
#include "FoodItem.h"
#include "Anthill.h"

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Queen : public Role
{
public:
	virtual void Work() override;
	virtual void Eat(Ant& ant, Food& food) override;
	Queen(Informer* informer) : informer(informer) {}
private:
	Informer* informer;
};