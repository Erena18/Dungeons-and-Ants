#include "Header.h"
#include <iostream>
using namespace std;
int main() 
{
    //�������� ����������� ����������������� ����...
    Ant ant(100, 0, 0, nullptr);
    for (int day = 0; day <= 100; ++day) 
    {
        ant.updateRole();
        cout << "����: " << day << ", �������: " << ant.getAge() << ", ����: ";

        Role* currentRole = ant.getRole();

        if (dynamic_cast<Child*>(currentRole)) cout << "�������";
        else if (dynamic_cast<Nanny*>(currentRole)) cout << "������";
        else if (dynamic_cast<Soldier*>(currentRole)) cout << "������";
        else if (dynamic_cast<Heardsant*>(currentRole)) cout << "������";
        else if (dynamic_cast<Builder*>(currentRole)) cout << "���������";
        else if (dynamic_cast<Collector*>(currentRole)) cout << "����������";
        else if (dynamic_cast<Cleaner*>(currentRole)) cout << "�������";

        cout << endl;
        ant.incrementAge();
    }

    return 0;
}