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

void Nanny::Work()
{
	//гдеяэ мюдн пеюкхгнбюрэ, врн мъмэйю 
	//мюундхряъ б ндмни йнлмюре я дерэлх
	//р.й. е╗ опълюъ пюанрю - йнплхрэ дереи
}

void Nanny::Eat(Ant& ant, int& food)
{
	if (food < 7)
	{
		ant.loseHp(5);
	}
	else
	{
		ant.restoreHp(10);
		food -= 7;
	}
}