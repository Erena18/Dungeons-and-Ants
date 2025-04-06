// CentralWarehouse.cpp
#include "CentralWarehouse.h"
#include "Anthill.h"
#include <cstdlib>
#include <iostream>

CentralWarehouse::CentralWarehouse()
    : Building(400, 1, 0), extensionCostPer50Units(125) {
}

void CentralWarehouse::dailyUpdate() {
    // Логика для центрального склада

    // Каждый день в центральный склад поступает случайное количество материалов
    int materialsIncoming = rand() % 30 + 20; // От 20 до 49 единиц приходящих материалов
    Anthill::getInstance().addMaterials(materialsIncoming);

    // Проверка общего количества материалов
    int currentMaterials = Anthill::getInstance().getMaterials().getAmount();
    int warehouseCapacity = getCapacity(); // Получаем общую вместимость
}

void CentralWarehouse::extend(int additionalCapacity, int cost) {
    if (cost >= extensionCostPer50Units && cost <= extensionCostPer50Units + 25) {
        // Проверяем, есть ли достаточное количество материалов
        int materialsAvailable = Anthill::getInstance().getMaterials().getAmount();
        if (materialsAvailable >= cost) {
            capacity += additionalCapacity;
            Anthill::getInstance().getMaterials().use(cost);
            // Увеличиваем стоимость следующего расширения
            extensionCostPer50Units += 25;
        }
    }
}