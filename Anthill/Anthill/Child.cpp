#include "Child.h"
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

//CHILD
void Child::Eat(Ant& ant, int& food)
{
	/*

	if (!hasNanny) //��� ������� ��, ��� ������ ���������� ������ ����,
	{
		//��������: ���� ������
		return;
	}

	*/
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
	return; // ���� �� ��������
}