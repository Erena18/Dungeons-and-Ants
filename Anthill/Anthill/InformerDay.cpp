#include "InformerDay.h"
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

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
		//� ������, ����� ���� �����, ��� ������ ��������� � ����� 
		//�, ��������, ���������� ImHere ���������� true � ���� ����� ������
	}
}