#pragma once
#include "Role.h"
#include "Ant.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

//здесь перечисленно либо, что не успела, либо не мое
class Queen : public Role
{
public:
	virtual void Work() override
	{
		cout << "королева Работает" << endl;
	}
	virtual void Eat(Ant& ant, int& food) override;
};