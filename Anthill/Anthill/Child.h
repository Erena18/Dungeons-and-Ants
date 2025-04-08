#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Nanny.h"
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

class Child : public Role
{
public:
	virtual void Work() override
	{
		cout << "ребенок Работает" << endl;
	}
	virtual void Eat(Ant& ant, int& food) override;
};