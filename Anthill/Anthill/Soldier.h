#pragma once
#include "Role.h"
#include "Ant.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

//Пишу не я, но добавлю, чтобы синтаксических ошибок не было

class Soldier : public Role
{
public:
	virtual void Work() override
	{
		cout << "солдат Работает" << endl;
	}
	virtual void Eat(Ant& ant, int& food) override;
};