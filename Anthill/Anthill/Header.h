#pragma once
#include <iostream>
#include <memory>
using namespace std;

class Role //абстрактный класс Role
{
public:
	virtual void Work() = 0; //чистая виртуальная функция «Work»
	virtual void Eat(Ant& ant, int& food) = 0;
	virtual ~Role() {};
};

class Ant
{
public:
	Ant();
	Ant(int initHp, int initAge, unique_ptr<Role> initRole);

	int getHp() const { return hp; }
	int getAge() const { return age; }

	void growth();
	void updateRole();
	void loseHp(int damageHp);
	void restoreHp(int point);
	void die();
	
	//Виртуальные
	void Work();
	void Eat(Ant& ant, int& food);

private:
	int hp, age;
	unique_ptr<Role> role;
};

class Nanny : public Role
{
public:
	virtual void Work() override;
	virtual void Eat(Ant& ant, int& food) override;
};

class Child : public Role
{
public:
	virtual void Work() override
	{
		cout << "ребенок Работает" << endl;
	}
	virtual void Eat(Ant& ant, int& food) override;
};


//здесь перечисленно либо, что не успела, либо не мое
class Queen : public Role
{
public:
	virtual void Work() override
	{
		cout << "королева Работает" << endl;
	}
};

class Builder : public Role
{
public:
	virtual void Work() override
	{
		cout << "строитель Работает" << endl;
	}
};

class Cleaner : public Role
{
public:
	virtual void Work() override
	{
		cout << "уборщик Работает" << endl;
	}
};

//Пишу не я, но добавлю, чтобы синтаксических ошибок не было

class Soldier : public Role
{
public:
	virtual void Work() override
	{
		cout << "солдат Работает" << endl;
	}
};

class Heardsant : public Role //пастух :)
{
public:
	virtual void Work() override 
	{
		cout << "пастух Работает" << endl;
	}
};

class Collector : public Role
{
public:
	virtual void Work() override
	{
		cout << "собиратель Работает" << endl;
	}
};


class Food 
{
public:
	Food(int amtFd) : amountFood(amtFd) {}

	int getAmountFood() const { return amountFood; }

	void consume(int amtFd) 
	{
		if (amtFd <= amountFood)
			amountFood -= amtFd;
		else
			amountFood = 0;
	}
private:
	int amountFood; 

};
