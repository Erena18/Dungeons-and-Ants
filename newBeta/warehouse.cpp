// Warehouse.cpp
#include "Warehouse.h"
#include "Anthill.h"
#include <cstdlib>
#include <iostream>

Warehouse::Warehouse()
    : Building(300, 2, 100) {
} // ����������� 300 ��., ���������� 2, ��������� 100 ��.

void Warehouse::dailyUpdate() {
    // ������ ��� ������

    // ���������� ������� ��������� ����������� ����������
    int materialsIncoming = rand() % 20 + 1; // 1-20 ������ ���������� ����������
    Anthill::getInstance().addMaterials(materialsIncoming);


    int currentMaterials = Anthill::getInstance().getMaterials().getAmount();
    int warehouseCapacity = getCapacity(); // �������� ����� ����������� ������

   
}