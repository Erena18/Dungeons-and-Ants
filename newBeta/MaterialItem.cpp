// MaterialItem.cpp
#include "MaterialItem.h"

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