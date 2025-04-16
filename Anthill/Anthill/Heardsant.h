#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"

using namespace std;

class Heardsant : public Role
{
public:
	virtual void Work(Ant& ant) override;
	virtual void Eat(Ant& ant, Food& food) override;
};