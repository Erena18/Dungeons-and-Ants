#pragma once
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Role //����������� ����� Role
{
public:
	virtual void Work() = 0; //������ ����������� ������� �Work�
	virtual void Eat(Ant& ant, int& food) = 0;
	virtual ~Role() {};
};
