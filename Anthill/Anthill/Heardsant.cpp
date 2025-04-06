#include "Heardsant.h"
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

//HEARDSANT
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