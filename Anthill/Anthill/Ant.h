#pragma once

#include "Role.h"
#include "Aphid.h"
#include "Nanny.h"
#include "Child.h"
#include "Queen.h"
#include "Builder.h"
#include "Cleaner.h"
#include "Soldier.h"
#include "Heardsant.h"
#include "Collector.h"

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Ant
{
public:
	Ant();
	Ant(int initHp, int initAge, unique_ptr<Role> initRole);

	int getHp() const { return hp; }
	int getAge() const { return age; }

	void growth();
	void updateRole();
	void loseHpEndDay();
	void loseHp(int damageHp);
	void restoreHp(int point);
	void die();

	void subscribeToInformer(Informer* informer);
	void unsubscribeFromInformer();
	Ant() : collectorInformer(new CollectorInformer()) {}
	Ant() : nannyInformer(new NannyInformer()) {}

	//Виртуальные
	virtual void Work();
	virtual void Eat(Ant& ant, Food& food);

	Ant(Vec2 startPos) : position(startPos) {}
	Vec2 getPosition() const { return position;	}


private:
	int hp, age;
	unique_ptr<Role> role;
	Informer* currentInformer = nullptr;
	CollectorInformer* collectorInformer;
	NannyInformer* nannyInformer;

	Vec2 position;
};