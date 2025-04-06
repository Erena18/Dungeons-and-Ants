#pragma once
#include "Role.h"
#include "Ant.h"
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