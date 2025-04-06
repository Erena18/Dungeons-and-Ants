#include "Queen.h"
#include "Child.h"
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

//QUEEN
void Queen::Eat(Ant& ant, int& food)
{
	if (food < 30)
	{
		ant.loseHp(30);
	}
	else
	{
		ant.restoreHp(20);
		food -= 30;
	}
}

void Queen::Work()
{
	int count = rand() % 11; //количество родившихся 0-10
	for (int i = 0; i < count; ++i)
	{
		unique_ptr<Ant> newAnt = make_unique<Ant>(100, 0, make_unique<Child>());
	}
}