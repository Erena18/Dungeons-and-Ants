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
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

Warehouse::Warehouse() : Building(400, 1, 0), extensionCostPer50Units(125) {}

void Warehouse::dailyUpdate() 
{
    // ������ ��� ������������ ������

    // ������ ���� � ����������� ����� ��������� ��������� ���������� ����������
    int materialsIncoming = rand() % 30 + 20; // �� 20 �� 49 ������ ���������� ����������
    Anthill::getInstance().addMaterials(materialsIncoming);

    // �������� ������ ���������� ����������
    int currentMaterials = Anthill::getInstance().getMaterials().getAmount();
    int warehouseCapacity = getCapacity(); // �������� ����� �����������
}

void Warehouse::extend(int additionalCapacity, int cost) 
{
    if (cost >= extensionCostPer50Units && cost <= extensionCostPer50Units + 25) 
    {
        // ���������, ���� �� ����������� ���������� ����������
        int materialsAvailable = Anthill::getInstance().getMaterials().getAmount();
        if (materialsAvailable >= cost) 
        {
            capacity += additionalCapacity;
            Anthill::getInstance().getMaterials().use(cost);
            // ����������� ��������� ���������� ����������
            extensionCostPer50Units += 25;
        }
    }
}