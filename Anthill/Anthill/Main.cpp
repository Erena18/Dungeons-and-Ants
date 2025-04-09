#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collector.h"
#include "Heardsant.h"
#include "Nanny.h"
#include "Queen.h"
#include "Soldier.h"

#include "Anthill.h"
#include "Building.h"
#include "Food.h"
#include "FoodItem.h"
#include "Garbage.h"
#include "GarbageManager.h"
#include "Materials.h"
#include "MaterialsItem.h"
#include "Warehouse.h"

#include "Zone.h"
#include "DangerousZone.h"
#include "EmptyZone.h"
#include "FoodZone.h"
#include "MaterialZone.h"
#include "PastureZone.h"

#include "AntLogic.h"
#include "Dimensions.h"

#include "Informers.h"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;
int main() 
{
    setlocale(LC_ALL, "Russian");
    //srand(time(0)); //надо уточнить, законно ли сдвигать время
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