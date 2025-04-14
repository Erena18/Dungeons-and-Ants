#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Food.h"

using namespace std;

class Aphid
{
public:
	Aphid();

	void growthAphid(int& amountFood);
	void dieAphid(int& amountFood);
	void loseHpAphid(int damageHp, int& amountFood);
	void restoreHpAphid(int point);
	void Eat(Food& food);
private:
	int hpAphid, ageAphid;

};