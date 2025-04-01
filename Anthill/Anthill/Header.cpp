#include "Header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Ant::Ant() : hp(100), age(0), role(nullptr) {}

Ant::Ant(int initHp, int initAge, int initExp, Role* initRole)
{
	hp = initHp;
	age = initAge;
	exp = initExp;
	Role* role = initRole;
}

void Ant::setRole(Role* newRole)
{
	if (role != nullptr)
	{
		delete role;
	}
	role = newRole;
}

void Ant::updateRole()
{
	//srand(time(0)); //надо уточнить, законно ли сдвигать время в функции
	if ((role != nullptr) && (dynamic_cast<Queen*>(role)))
	{
		return; //королева роли не меняет, абсолютная монархия
	}
	if (age < 20)
	{
		setRole(new Child());
		return;
	}
	else if ((age >=20) && (age < 39))
	{
		setRole(new Nanny());
		return;
	}
	else if ((age >= 40) && (age < 59))
	{
		rand();
		int check = rand() % 2;
		if (check == 0)
		{
			setRole(new Soldier());
			return; //Чувак не сдал ЕГЭ
		}
		else
		{
			setRole(new Heardsant());
			return; //Поздравляем с поступлением в Сельхоз. Институт!
		}
	}
	else if ((age >= 60) && (age < 79) && (dynamic_cast<Soldier*>(role)))
	{
		setRole(new Builder());
		return; //Боб строитель
	}
	else if ((age >= 60) && (age < 79) && (dynamic_cast<Heardsant*>(role)))
	{
		setRole(new Collector());
		return;
	}
	else if ((age >= 80) && (age < 100))
	{
		setRole(new Cleaner());
		return;
	}
	else if (age >= 100)
	{
		delete role;
		role = nullptr;
		return; // лёх и сдох
	}
}

Ant::~Ant() 
{
	delete role;
}
