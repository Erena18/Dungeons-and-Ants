#include "Food.h"

void Food::consume(int amtFd) {
    if (amtFd <= amountFood)
        amountFood -= amtFd;
    else
        amountFood = 0;
}

void Food::addFood(int amtFd) {
    amountFood += amtFd;
}