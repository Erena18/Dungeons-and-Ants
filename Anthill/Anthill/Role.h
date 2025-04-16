#pragma once

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Ant;
class Food;

class Role
{
public:
	virtual void Work(Ant& ant) = 0;
	virtual void Eat(Ant& ant, Food& food) = 0;
	virtual void Move(Ant& ant) = 0;
	virtual void onNotify(Ant& ant)
	{
		Work(ant);
	}
	virtual ~Role() = default;
};
