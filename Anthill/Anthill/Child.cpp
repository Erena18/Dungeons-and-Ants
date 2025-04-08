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
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

void Child::Eat(Ant& ant, int& food)
{
	if (!hasNanny) //это функци€ то, что должна возвращать работа н€ни,
	{
		//информер: ЌяЌя  ”Ўј“№
		return;
	}
	if (food < 5)
	{
		ant.loseHp(5);
	}
	else
	{
		ant.restoreHp(10);
		food -= 5;
	}
}
void Child::Work()
{
	return; // дети не работают
}