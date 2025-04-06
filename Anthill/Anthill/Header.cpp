/*
#include "Header.h"
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

//APHID
Aphid::Aphid() : hpAphid(20), ageAphid(0) {}

void Aphid::growthAphid(int& amountFood)
{
	ageAphid++;
	if ((hpAphid <= 0) || (ageAphid > 10))
	{
		dieAphid(amountFood);
	}
}

void Aphid::dieAphid(int& amountFood)
{
	//здесь должна быть реализация, что тля умерла внутри муравейника
	amountFood++;
	//если тля умерла на улице, она становится МУСОРОМ

	//новая рождается в муравейнике в любом случае
	auto newAphid = make_unique<Aphid>();
}

void Aphid::loseHpAphid(int damageHp, int& amountFood)
{
	hpAphid -= damageHp;
	if (hpAphid < 0)
	{
		//int countFood = getAmountFood();
		dieAphid(amountFood);
	}
}

void Aphid::restoreHpAphid(int point)
{
	hpAphid += point;
	if (hpAphid > 20)
	{
		hpAphid = 20;
	}
}

void Aphid::Eat(Aphid& aphid, int& amountFood)
{
	if (!hasHeardsant) // пастух, должен быть в радиусе n-метров от тли
	{
		//информер: ПАСТУХ КУШАТЬ
		return;
	}
	if (amountFood < 1)
	{
		aphid.loseHpAphid(3, amountFood);
	}
	else
	{
		aphid.restoreHpAphid(3);
		amountFood -= 3;
	}
}

//INFORMER 
void InformerDay::subscribe(Nanny* nanny)
{
	nannies.push_back(nanny);
}

void InformerDay::unsubscribe(Nanny* nanny)
{
	nannies.erase(remove(nannies.begin(), 
		nannies.end(), nanny), nannies.end());
}

void InformerDay::notifyChildrenWantToEat()
{
	for (Nanny* nanny : nannies) 
	{
		nanny->Work();
		//в планах, когда няню зовут, она должна прибежать к детям 
		//и, допустим, переменная ImHere становится true и дети могут поесть
	}
}


//NANNY
void Nanny::Work()
{
	//ЗДЕСЬ НАДО РЕАЛИЗОВАТЬ, ЧТО НЯНЬКА 
	//НАХОДИТСЯ В ОДНОЙ КОМНАТЕ С ДЕТЬМИ
	//Т.К. ЕЁ ПРЯМАЯ РАБОТА - КОРМИТЬ ДЕТЕЙ
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
void Child::Work()
{
	return; // дети не работают
}

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




/*
//BUILDER
void Builder::Eat(Ant& ant, int& food)
{
	if (food < 20)
	{
		ant.loseHp(15);
	}
	else
	{
		ant.restoreHp(20);
		food -= 20;
	}
}

//CLEANER
void Cleaner::Eat(Ant& ant, int& food)
{
	if (food < 10)
	{
		ant.loseHp(10);
	}
	else
	{
		ant.restoreHp(15);
		food -= 10;
	}
}

//SOLDIER
void Soldier::Eat(Ant& ant, int& food)
{
	if (food < 20)
	{
		ant.loseHp(15);
	}
	else
	{
		ant.restoreHp(20);
		food -= 20;
	}
}

//COLLECTOR
void Collector::Eat(Ant& ant, int& food)
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
*/

