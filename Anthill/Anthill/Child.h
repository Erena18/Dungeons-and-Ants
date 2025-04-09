#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Nanny.h"
#include "Queen.h"
#include "Builder.h"
#include "Cleaner.h"
#include "Soldier.h"
#include "Heardsant.h"
#include "Collector.h"

#include "Dimensions.h"
#include "AntLogic.h"

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Child : public Role
{
public:
	Child(Vec2 startPos) : position(startPos) {}

	virtual void Work() override;
	virtual void Eat(Ant& ant, Food& food) override;
	Child(NannyInformer* informer) : informer(informer) {}
	NannyInformer* getInformer() const { return informer; }
	void setInformer(NannyInformer* informer)
	{
		this->informer = informer;
	}
	Child(Vec2 startPos) : position(startPos) {}
	Vec2 getPosition() const { return position; }
private:
	NannyInformer* informer;
	Vec2 position;
};