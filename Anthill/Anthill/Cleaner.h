#pragma once
#include "Role.h"
#include "Ant.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Cleaner : public Role
{
public:
	virtual void Work() override
	{
		cout << "уборщик Работает" << endl;
	}
	virtual void Eat(Ant& ant, int& food) override;
};