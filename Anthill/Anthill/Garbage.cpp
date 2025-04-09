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

Garbage::Garbage(Type type, int weight): type(type), weight(weight) {}

Garbage::Type Garbage::getType() const 
{
    return type;
}

int Garbage::getWeight() const 
{
    return weight;
}