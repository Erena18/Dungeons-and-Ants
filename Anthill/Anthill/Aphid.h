#pragma once
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Aphid
{
public:
	Aphid();

	void growthAphid(int& amountFood);
	void dieAphid(int& amountFood);
	void loseHpAphid(int damageHp, int& amountFood);
	void restoreHpAphid(int point);
private:
	int hpAphid, ageAphid;

};