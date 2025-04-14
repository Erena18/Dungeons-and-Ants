#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Role.h"
#include "Ant.h"
#include "Informers.h"

using namespace std;

class Child : public Role
{
public:
	//Child(Vec2 startPos) : position(startPos) {}

	Child();

	virtual void Work() override;
	virtual void Eat(Ant& ant, Food& food) override;
	Child(NannyInformer* informer) : informer(informer) {}
	NannyInformer* getInformer() const { return informer; }
	void setInformer(NannyInformer* informer)
	{
		this->informer = informer;
	}
	//здесь ошибка 
	//Child(Vec2 startPos) : position(startPos) {}
	//Vec2 getPosition() const { return position; }
private:
	NannyInformer* informer;
	//Vec2 position;
};