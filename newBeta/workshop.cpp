// Workshop.cpp
#include "Workshop.h"
#include "Anthill.h"
#include <cstdlib>

Workshop::Workshop()
    : Building(150, 1, 75) {
}

void Workshop::dailyUpdate() {
    // ������������ ����������
    int materialsProduced = rand() % 5 + 1; // ���������� 1-5 ��. ����������
    Anthill::getInstance().addMaterials(materialsProduced);
}