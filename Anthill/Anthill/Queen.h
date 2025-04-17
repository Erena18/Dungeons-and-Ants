#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Role.h"
#include "Ant.h"
#include "Child.h"
#include "Anthill.h"

using namespace std;


class Queen : public Role
{
public:
	virtual void Work(Ant& ant) override;
	virtual void Eat(Ant& ant, Food& food) override;
	//void Move(Ant& ant) override;
	//Queen(Informer* informer) : informer(informer) {}
private:
	//Informer* informer;
};