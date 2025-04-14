#pragma once
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Food.h"

using namespace std;

class FoodItem 
{
public:
    FoodItem(int amount);

    int getAmount() const;
    int getAge() const;

    void increaseAge();
    bool isSpoiled() const;
    void reduceAmount(int amountToReduce);

private:
    int amount;
    int age; 
};