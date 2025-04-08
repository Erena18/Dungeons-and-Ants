#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Nanny.h"
#include "Child.h"
#include "Queen.h"
#include "Builder.h"
#include "Cleaner.h"
#include "Soldier.h"
#include "Heardsant.h"
#include "Collector.h"
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

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
	//����� ������ ���� ����������, ��� ��� ������ ������ �����������
	amountFood++;
	//���� ��� ������ �� �����, ��� ���������� �������

	//����� ��������� � ����������� � ����� ������
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
	if (!hasHeardsant) // ������, ������ ���� � ������� n-������ �� ���
	{
		//��������: ������ ������
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