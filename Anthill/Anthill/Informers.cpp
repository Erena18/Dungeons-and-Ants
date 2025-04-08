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
	subscribers.push_back(role);
}

void Informer::unsubscribe(Role* role)
{
	subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), role), subscribers.end());
}

void Informer::notify(const std::string& message)
{
	for (Role* subscriber : subscribers)
	{
		subscriber->Work(); //ÃŒ∆ÕŒ À» “¿ ??????????????
	}
}