#pragma once
#ifndef FOOD_H
#define FOOD_H

class Food {
public:
    Food(int amtFd) : amountFood(amtFd) {}

    int getAmountFood() const { return amountFood; }

    void consume(int amtFd);

    void addFood(int amtFd);

private:
    int amountFood;
};

#endif // FOOD_H 

