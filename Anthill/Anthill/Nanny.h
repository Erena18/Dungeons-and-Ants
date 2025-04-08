#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
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

class Nanny : public Role
{
public:
	virtual void Work() override;
	virtual void Eat(Ant& ant, int& food) override;
};