#include "Ant.h"
#include "Aphid.h"
#include "Builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collector.h"
#include "Food.h"
#include "Heardsant.h"
#include "InformerDay.h"
#include "Nanny.h"
#include "Queen.h"
#include "Role.h"
#include "Soldier.h"
#include "Visual.h"

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

int main()
{
    //setlocale(LC_ALL, "Russian");
    //Проверка минимальной работоспособности кода...
    /*unique_ptr<Role> initialRole = make_unique<Child>();
    Ant ant(100, 0, move(initialRole));

    for (int day = 1; day < 100; ++day) 
    {
        cout << "День: " << day << ", Возраст: " << ant.getAge() << ", Здоровье: " << ant.getHp() << endl;
        if (ant.getHp() <= 0 || ant.getAge() >= 99) 
        {
            cout << "Муравей умер." << endl;
            break;
        }
        ant.growth();
    }*/

    return 0;
}