// Warehouse.cpp
#include "Warehouse.h"
#include "Anthill.h"
#include <cstdlib>
#include <iostream>

Warehouse::Warehouse()
    : Building(300, 2, 100) {
} // Вместимость 300 ед., количество 2, стоимость 100 ед.

void Warehouse::dailyUpdate() {
    // Логика для склада

    // Пополнение запасов случайным количеством материалов
    int materialsIncoming = rand() % 20 + 1; // 1-20 единиц приходящих материалов
    Anthill::getInstance().addMaterials(materialsIncoming);


    int currentMaterials = Anthill::getInstance().getMaterials().getAmount();
    int warehouseCapacity = getCapacity(); // Получаем общую вместимость склада

   
}