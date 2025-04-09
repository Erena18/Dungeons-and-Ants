#pragma once

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

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Ant;
class Food;
class Collector;
class Anthill; 
class Warehouse;


class Role
{
public:
	virtual void Work() = 0;
	virtual void Eat(Ant& ant, Food& food) = 0;
	virtual ~Role() {};
};
