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
#include <vector>
#include <memory>
using namespace std;
int main() 
{
    setlocale(LC_ALL, "Russian");
    //srand(time(0)); //���� ��������, ������� �� �������� �����
    //�������� ����������� ����������������� ����...
    /*unique_ptr<Role> initialRole = make_unique<Child>();
    Ant ant(100, 0, move(initialRole));

    for (int day = 1; day < 100; ++day) 
    {
        cout << "����: " << day << ", �������: " << ant.getAge() << ", ��������: " << ant.getHp() << endl;
        if (ant.getHp() <= 0 || ant.getAge() >= 99) 
        {
            cout << "������� ����." << endl;
            break;
        }
        ant.growth();
    }*/

    return 0;
}