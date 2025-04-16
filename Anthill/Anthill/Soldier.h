#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Role.h"
#include "Ant.h"

using namespace std;

class Soldier : public Role
{
public:
	//virtual void Work(Ant& ant) override;
	virtual void Eat(Ant& ant, Food& food) override;
};