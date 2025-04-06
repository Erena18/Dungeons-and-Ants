#pragma once
#include "Ant.h"
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