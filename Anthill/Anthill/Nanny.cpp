#include "Nanny.h"
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

//NANNY
void Nanny::Work()
{
	//����� ���� �����������, ��� ������ 
	//��������� � ����� ������� � ������
	//�.�. Ũ ������ ������ - ������� �����
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