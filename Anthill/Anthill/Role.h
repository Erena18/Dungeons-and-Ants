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
	virtual void Work() = 0;
	virtual void Eat(Ant& ant, Food& food) = 0;
	virtual ~Role() {};
};
