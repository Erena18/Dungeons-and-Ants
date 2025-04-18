#pragma once
#include <SFML/System.hpp>
#include <iostream>
#include <memory>
#include <vector>

#include "Role.h"
#include "Ant.h"
#include "Informers.h"

using namespace std;
using namespace sf;

class Builder : public Role
{
public:
	void Work(Ant& ant) override;
	void Eat(Ant& ant, Food& food) override;
	void Move(Ant& ant) override;


	/*Builder(CollectorInformer* informer) : informer(informer) {}
	CollectorInformer* getInformer() const { return informer; }
	void setInformer(CollectorInformer* informer) 
	{
		this->informer = informer;
	}*/
private:
	Clock workClock;
	float workInterval = 6.f;
	//CollectorInformer* informer;
};