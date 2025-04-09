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

#include "Food.h"
#include "FoodItem.h"
#include "Anthill.h"

#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include "Informers.h"
using namespace std;

void Informer::subscribe(Role* role)
{
	if (role != nullptr && find(subscribers.begin(), 
		subscribers.end(), role) == subscribers.end()) 
	{
		subscribers.push_back(role);
	}
}

void Informer::unsubscribe(Role* role)
{
	subscribers.erase(remove(subscribers.begin(), subscribers.end(), role), subscribers.end());
}

void Informer::notify()
{
	for (Role* role : subscribers) 
	{
		role->Work();
	}
}

//COLLECTORS
void CollectorInformer::addCollector(Collector* collector)
{
	collectors.push_back(collector);
}

void CollectorInformer::notify()
{
	for (auto& collector : collectors)
	{
		collector->Work();
	}
}
