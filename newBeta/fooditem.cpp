// FoodItem.cpp
#include "FoodItem.h"

FoodItem::FoodItem(int amount)
    : amount(amount), age(0) {
}

int FoodItem::getAmount() const {
    return amount;
}

int FoodItem::getAge() const {
    return age;
}

void FoodItem::increaseAge() {
    age++;
}

bool FoodItem::isSpoiled() const {
    return age >= 10;
}

void FoodItem::reduceAmount(int amountToReduce) {
    if (amountToReduce >= amount) {
        amount = 0;
    }
    else {
        amount -= amountToReduce;
    }
}