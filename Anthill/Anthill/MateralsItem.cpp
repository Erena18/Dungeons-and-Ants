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

MaterialItem::MaterialItem(int amount)
    : amount(amount), age(0) {
}

int MaterialItem::getAmount() const {
    return amount;
}

int MaterialItem::getAge() const {
    return age;
}

void MaterialItem::increaseAge() {
    age++;
}

bool MaterialItem::isSpoiled() const {
    return age >= 10;
}

void MaterialItem::reduceAmount(int amountToReduce) {
    if (amountToReduce >= amount) {
        amount = 0;
    }
    else {
        amount -= amountToReduce;
    }
}