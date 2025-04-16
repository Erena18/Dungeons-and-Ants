#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include "FoodItem.h"
#include "GarbageManager.h"

using namespace std;
using namespace sf;

class Food 
{
public:
    Food();

    void addFood(int amount);
    int consume(int amount);

    int getTotalAmount() const;
    void dailyUpdate();

    void drawAll(RenderWindow& window);

private:
    vector<FoodItem> foodItems;
};
