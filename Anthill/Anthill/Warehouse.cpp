#include "Anthill.h"
#include "Building.h"
#include "Warehouse.h"
#include "Food.h"
#include "FoodItem.h"
#include "Materials.h"
#include "MaterialsItem.h"
#include "Garbage.h"
#include "GarbageManager.h"
#include "Workshop.h"

#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

Warehouse::Warehouse()
    : Building(400, 1, 0), extensionCostPer50Units(125) {
}

void Warehouse::dailyUpdate() {
    // Логика для центрального склада

    // Каждый день в центральный склад поступает случайное количество материалов
    int materialsIncoming = rand() % 30 + 20; // От 20 до 49 единиц приходящих материалов
    Anthill::getInstance().addMaterials(materialsIncoming);

    // Проверка общего количества материалов
    int currentMaterials = Anthill::getInstance().getMaterials().getAmount();
    int warehouseCapacity = getCapacity(); // Получаем общую вместимость
}

void Warehouse::extend(int additionalCapacity, int cost) 
{
    if (cost >= extensionCostPer50Units && cost <= extensionCostPer50Units + 25) 
    {
        // Проверяем, есть ли достаточное количество материалов
        int materialsAvailable = Anthill::getInstance().getMaterials().getAmount();
        if (materialsAvailable >= cost) 
        {
            capacity += additionalCapacity;
            Anthill::getInstance().getMaterials().use(cost);
            // Увеличиваем стоимость следующего расширения
            extensionCostPer50Units += 25;
        }
    }
}