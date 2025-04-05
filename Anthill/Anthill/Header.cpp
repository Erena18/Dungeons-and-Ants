#include "Header.h"
#include <iostream>
#include <cstdlib>
#include <memory>
#include <ctime>
using namespace std;

Ant::Ant() : hp(100), age(0), role(nullptr) {}

Ant::Ant(int initHp, int initAge, unique_ptr<Role> initRole) :
	hp(initHp), age(initAge), role(move(initRole)) {}

void Ant::updateRole()
{
	//srand(time(0)); //надо уточнить, законно ли сдвигать время в функции
	if ((role != nullptr) && (dynamic_cast<Queen*>(role.get())))
	{
		return; //королева роли не меняет, абсолютная монархия
	}
	if (age < 20)
	{
		role = make_unique<Child>();
		return;
	}
	else if ((age >=20) && (age < 39))
	{
		role = make_unique<Nanny>();
		return;
	}
	else if ((age >= 40) && (age < 59))
	{
		rand();
		int check = rand() % 2;
		if (check == 0)
		{
			role = make_unique<Soldier>();
			return; //Чувак не сдал ЕГЭ
		}
		else
		{
			role = make_unique<Heardsant>();
			return; //Поздравляем с поступлением в Сельхоз. Институт!
		}
	}
	else if ((age >= 60) && (age < 79) && (dynamic_cast<Soldier*>(role.get())))
	{
		role = make_unique<Builder>();
		return; //Боб строитель
	}
	else if ((age >= 60) && (age < 79) && (dynamic_cast<Heardsant*>(role.get())))
	{
		role = make_unique<Collector>();
		return;
	}
	else if ((age >= 80) && (age < 100))
	{
		role = make_unique<Cleaner>();
		return;
	}
	else if (age >= 100)
	{
		return; // лёх и сдох
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
	if ((hp <= 0) || (age >= 100))
	{
		die(); //НАПИСАТЬ
	}
}

void Ant::die()
{
	delete this; // смэрть
}

void Ant::Work()
{
	if (role != nullptr)
	{
		role->Work();
	}
}

void Ant::Eat(Ant& ant, int& food)
{
	if (role != nullptr)
	{
		role->Eat(*this, food);
	}
}


//NANNY
void Nanny::Work()
{
	//ЗДЕСЬ НАДО РЕАЛИЗОВАТЬ, ЧТО НЯНЬКА 
	//НАХОДИТСЯ В ОДНОЙ КОМНАТЕ С ДЕТЬМИ
	//Т.К. ЕЁ ПРЯМАЯ РАБОТА - КОРМИТЬ ДЕТЕЙ
}


//CHILD
void Child::Eat(Ant& ant, int& food)
{
	if (!hasNanny) //это функция то, что должна возвращать работа няни,
	{
		//информер: НЯНЯ КУШАТЬ
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
