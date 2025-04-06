#pragma once
#include "Role.h"
#include "Ant.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Collector : public Role
{
public:
	virtual void Work() override
	{
		cout << "собиратель Работает" << endl;
	}
	virtual void Eat(Ant& ant, int& food) override;
};