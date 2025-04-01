#include "Header.h"
#include <iostream>
using namespace std;
int main() 
{
    //Проверка минимальной работоспособности кода...
    Ant ant(100, 0, 0, nullptr);
    for (int day = 0; day <= 100; ++day) 
    {
        ant.updateRole();
        cout << "День: " << day << ", Возраст: " << ant.getAge() << ", Роль: ";

        Role* currentRole = ant.getRole();

        if (dynamic_cast<Child*>(currentRole)) cout << "Ребенок";
        else if (dynamic_cast<Nanny*>(currentRole)) cout << "Нянька";
        else if (dynamic_cast<Soldier*>(currentRole)) cout << "Солдат";
        else if (dynamic_cast<Heardsant*>(currentRole)) cout << "Пастух";
        else if (dynamic_cast<Builder*>(currentRole)) cout << "Строитель";
        else if (dynamic_cast<Collector*>(currentRole)) cout << "Собиратель";
        else if (dynamic_cast<Cleaner*>(currentRole)) cout << "Уборщик";

        cout << endl;
        ant.incrementAge();
    }

    return 0;
}