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
	//srand(time(0)); //���� ��������, ������� �� �������� ����� � �������
	if ((role != nullptr) && (dynamic_cast<Queen*>(role)))
	{
		return; //�������� ���� �� ������, ���������� ��������
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
			return; //����� �� ���� ���
		}
		else
		{
			setRole(new Heardsant());
			return; //����������� � ������������ � �������. ��������!
		}
	}
	else if ((age >= 60) && (age < 79) && (dynamic_cast<Soldier*>(role)))
	{
		setRole(new Builder());
		return; //��� ���������
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
		return; // �� � ����
	}
}

Ant::~Ant() 
{
	delete role;
}
