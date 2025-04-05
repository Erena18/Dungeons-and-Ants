#pragma once
#include <iostream>
#include <memory>
using namespace std;

class Role //����������� ����� Role
{
public:
	virtual void Work() = 0; //������ ����������� ������� �Work�
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
	
	//�����������
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
		cout << "������� ��������" << endl;
	}
	virtual void Eat(Ant& ant, int& food) override;
};


//����� ������������ ����, ��� �� ������, ���� �� ���
class Queen : public Role
{
public:
	virtual void Work() override
	{
		cout << "�������� ��������" << endl;
	}
};

class Builder : public Role
{
public:
	virtual void Work() override
	{
		cout << "��������� ��������" << endl;
	}
};

class Cleaner : public Role
{
public:
	virtual void Work() override
	{
		cout << "������� ��������" << endl;
	}
};

//���� �� �, �� �������, ����� �������������� ������ �� ����

class Soldier : public Role
{
public:
	virtual void Work() override
	{
		cout << "������ ��������" << endl;
	}
};

class Heardsant : public Role //������ :)
{
public:
	virtual void Work() override 
	{
		cout << "������ ��������" << endl;
	}
};

class Collector : public Role
{
public:
	virtual void Work() override
	{
		cout << "���������� ��������" << endl;
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
