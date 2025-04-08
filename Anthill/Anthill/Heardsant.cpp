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

void Heardsant::Eat(Ant& ant, int& food)
{
	if (food < 15)
	{
		ant.loseHp(10);
	}
	else
	{
		ant.restoreHp(15);
		food -= 15;
	}
}