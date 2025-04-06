
#ifndef FOOD_H
#define FOOD_H

#include "FoodItem.h"
#include <vector>

class Food {
public:
    Food();

    void addFood(int amount);
    int consume(int amount);

    int getTotalAmount() const;
    void dailyUpdate(); // ����������� ������� ��� � ������� �����������

private:
    std::vector<FoodItem> foodItems;
};

#endif // FOOD_H