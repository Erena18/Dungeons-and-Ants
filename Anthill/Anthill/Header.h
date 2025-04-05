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
	void loseHpEndDay();
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

class Aphid
{
public:
	Aphid();

	void growthAphid(int& amountFood);
	void dieAphid(int& amountFood);
	void loseHpAphid(int damageHp, int& amountFood);
	void restoreHpAphid(int point);
private:
	int hpAphid, ageAphid;

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
	virtual void Eat(Ant& ant, int& food) override;
};

class Builder : public Role
{
public:
	virtual void Work() override
	{
		cout << "строитель Работает" << endl;
	}
	virtual void Eat(Ant& ant, int& food) override;
};

class Cleaner : public Role
{
public:
	virtual void Work() override
	{
		cout << "уборщик Работает" << endl;
	}
	virtual void Eat(Ant& ant, int& food) override;
};

//Пишу не я, но добавлю, чтобы синтаксических ошибок не было

class Soldier : public Role
{
public:
	virtual void Work() override
	{
		cout << "солдат Работает" << endl;
	}
	virtual void Eat(Ant& ant, int& food) override;
};

class Heardsant : public Role //пастух :)
{
public:
	virtual void Work() override 
	{
		cout << "пастух Работает" << endl;
	}
	virtual void Eat(Ant& ant, int& food) override;
};

class Collector : public Role
{
public:
	virtual void Work() override
	{
		cout << "собиратель Работает" << endl;
	}
	virtual void Eat(Ant& ant, int& food) override;
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
