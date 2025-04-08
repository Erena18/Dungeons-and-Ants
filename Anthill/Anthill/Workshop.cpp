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

Workshop::Workshop() : Building(150, 1, 75) {}

void Workshop::dailyUpdate() 
{
    // Производство материалов
    int materialsProduced = rand() % 5 + 1; // Производим 1 - 5 ед.материалов
    Anthill::getInstance().addMaterials(materialsProduced);
}