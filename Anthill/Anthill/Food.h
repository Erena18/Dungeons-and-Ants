#pragma once
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Food 
{
public:
	Food(int amtFd) : amountFood(amtFd) {}

	int getAmountFood() const { return amountFood; }

	void consume(int amtFd) 
	{
		if (amtFd <= amountFood)
			amountFood -= amtFd;
		else
			amountFood = 0;
	}
private:
	int amountFood; 

};
