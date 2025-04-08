#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Nanny.h"
#include "Child.h"
#include "Queen.h"
#include "Builder.h"
#include "Cleaner.h"
#include "Soldier.h"
#include "Collector.h"

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Heardsant : public Role //пастух :)
{
public:
	virtual void Work() override
	{
		cout << "пастух Работает" << endl;
	}
	virtual void Eat(Ant& ant, int& food) override;
};