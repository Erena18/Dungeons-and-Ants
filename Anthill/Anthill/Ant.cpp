#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Nanny.h"
#include "Child.h"
#include "Queen.h"
#include "Builder.h"
#include "Cleaner.h"
#include "Soldier.h"
#include "Heardsant.h"
#include "Collector.h"

#include "Informers.h"

#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

Ant::Ant() : hp(100), age(0), role(nullptr) {}

Ant::Ant(int initHp, int initAge, unique_ptr<Role> initRole) :
	hp(initHp), age(initAge), role(move(initRole)) {}

void Ant::updateRole()
{
	if ((role != nullptr) && (dynamic_cast<Queen*>(role.get())))
	{
		return;
	}
	Informer* previousInformer = currentInformer;
	if (age < 20)
	{
		role = make_unique<Child>();
		return;
	}
	else if ((age >= 20) && (age < 39))
	{
		role = make_unique<Nanny>();
		NannyInformer* nannyInformer;
		nannyInformer->subscribe(role.get());
		currentInformer = nannyInformer;
		return;
	}
	else if ((age >= 40) && (age < 59))
	{
		rand();
		int check = rand() % 2;
		if (check == 0)
		{
			role = make_unique<Soldier>();
			SoldierInformer* soldierInformer;
			soldierInformer->subscribe(role.get());
			currentInformer = soldierInformer;
			return;
		}
		else
		{
			role = make_unique<Heardsant>();
			return;
		}
	}
	else if ((age >= 60) && (age < 79) && (dynamic_cast<Soldier*>(role.get())))
	{
		role = make_unique<Builder>(collectorInformer);
		return;
	}
	else if ((age >= 60) && (age < 79) && (dynamic_cast<Heardsant*>(role.get())))
	{
		role = make_unique<Collector>();
		CollectorInformer* collectorInformer;
		collectorInformer->subscribe(role.get());
		currentInformer = collectorInformer;
		return;
	}
	else if ((age >= 80) && (age < 100))
	{
		role = make_unique<Cleaner>();
		CleanerInformer* cleanerInformer;
		cleanerInformer->subscribe(role.get());
		currentInformer = cleanerInformer;
		return;
	}
	else if (age >= 100)
	{			
		currentInformer->unsubscribe(role.get());
		die();
		return;
	}
	if (previousInformer)
	{
		previousInformer->unsubscribe(role.get());
	}
}

void Ant::loseHpEndDay()
{
	hp -= rand() % 11;
	if (hp < 0)
	{
		die();
	}
}

void Ant::loseHp(int damageHp)
{
	hp -= damageHp;
	if (hp < 0)
	{
		die();
	}
}

void Ant::restoreHp(int point)
{
	hp += point;
	if (hp > 100)
	{
		hp = 100;
	}
}

void Ant::growth()
{
	age++;
	updateRole();
	if ((hp <= 0) || (age > 100))
	{
		die();
	}
}

void Ant::die()
{
	delete this;
}

void Ant::subscribeToInformer(Informer* informer)
{
	if (currentInformer) 
	{
		currentInformer->unsubscribe(role.get());
	}
	currentInformer = informer;
	if (currentInformer) 
	{
		currentInformer->subscribe(role.get());
	}
}

void Ant::unsubscribeFromInformer()
{
	if (currentInformer) 
	{
		currentInformer->unsubscribe(role.get());
		currentInformer = nullptr;
	}
}

void Ant::Work()
{
	if (role != nullptr)
	{
		role->Work();
	}
}

void Ant::Eat(Ant& ant, Food& food)
{
	if (role != nullptr)
	{
		role->Eat(*this, food);
	}
}