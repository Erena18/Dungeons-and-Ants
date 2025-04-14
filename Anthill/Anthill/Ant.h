#pragma once

/*#include "Aphid.h"
#include "Builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collector.h"
#include "Heardsant.h"
#include "Nanny.h"
#include "Queen.h"
#include "Soldier.h"*/


/*#include "Building.h"
#include "FoodItem.h"
#include "Garbage.h"
#include "GarbageManager.h"
#include "Materials.h"
#include "MaterialsItem.h"
#include "Warehouse.h"*/

#include <iostream>
#include <memory>
#include <vector>

#include "Role.h"
#include "Anthill.h"
#include "Food.h"
#include "Zone.h"
#include "Informers.h"

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
	/*Ant() : collectorInformer(new CollectorInformer()) {}
	Ant() : nannyInformer(new NannyInformer()) {}
	Ant() : cleanerInformer(new CleanerInformer()) {}
	Ant() : soldierInformer(new SoldierInformer()) {}*/

	//Виртуальные
	virtual void Work();
	virtual void Eat(Ant& ant, Food& food);

	//Ant(Vec2 startPos) : position(startPos) {}
	//Vec2 getPosition() const { return position;	}


private:
	int hp, age;
	unique_ptr<Role> role;
	Informer* currentInformer = nullptr;
	CollectorInformer* collectorInformer;
	NannyInformer* nannyInformer;
	CleanerInformer* cleanerInformer;
	SoldierInformer* soldierInformer;

};