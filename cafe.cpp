#pragma once
#include "cafe.h"
//#include <iostream>

FoodZone::FoodZone() 
    : zoneType("food"), capacity(50), currentFood(50) {}

// Метод для сбора еды
int FoodZone::collectFood(int amount) {
    if (currentFood <= 0) {
        //std::cout << "No food left" << std::endl;
        return 0;
    }
    int collected = std::min(amount, currentFood);
    currentFood -= collected;
    //std::cout << "Has been gathered" << collected << "of food" << std::endl;
    return collected;
}

// Метод для пополнения еды
void FoodZone::replenishFood() {
    if (currentFood < capacity) {
        currentFood += 1;
        //std::cout << "Food is available. Total amount is:  " << currentFood << std::endl;
    } else {
        //std::cout << "Food is available" << std::endl;
    }
}

// Метод для проверки, доступна ли еда
bool FoodZone::hasFood() const {
    return currentFood > 0;
}

// Получения текущего количества еды
int FoodZone::getFoodAmount() const {
    return currentFood;
}