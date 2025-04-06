#pragma once
#include "Role.h"
#include "Ant.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

//����� ������������ ����, ��� �� ������, ���� �� ���
class Queen : public Role
{
public:
	virtual void Work() override
	{
		cout << "�������� ��������" << endl;
	}
	virtual void Eat(Ant& ant, int& food) override;
};