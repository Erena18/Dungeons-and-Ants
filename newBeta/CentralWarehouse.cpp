// CentralWarehouse.cpp
#include "CentralWarehouse.h"
#include "Anthill.h"
#include <cstdlib>
#include <iostream>

CentralWarehouse::CentralWarehouse()
    : Building(400, 1, 0), extensionCostPer50Units(125) {
}

void CentralWarehouse::dailyUpdate() {
    // ������ ��� ������������ ������

    // ������ ���� � ����������� ����� ��������� ��������� ���������� ����������
    int materialsIncoming = rand() % 30 + 20; // �� 20 �� 49 ������ ���������� ����������
    Anthill::getInstance().addMaterials(materialsIncoming);

    // �������� ������ ���������� ����������
    int currentMaterials = Anthill::getInstance().getMaterials().getAmount();
    int warehouseCapacity = getCapacity(); // �������� ����� �����������
}

void CentralWarehouse::extend(int additionalCapacity, int cost) {
    if (cost >= extensionCostPer50Units && cost <= extensionCostPer50Units + 25) {
        // ���������, ���� �� ����������� ���������� ����������
        int materialsAvailable = Anthill::getInstance().getMaterials().getAmount();
        if (materialsAvailable >= cost) {
            capacity += additionalCapacity;
            Anthill::getInstance().getMaterials().use(cost);
            // ����������� ��������� ���������� ����������
            extensionCostPer50Units += 25;
        }
    }
}