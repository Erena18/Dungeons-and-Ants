#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include <vector>

#include "Food.h"

using namespace std;
using namespace sf;

class Aphid
{
public:
	Aphid();

	void growthAphid(int& amountFood);
	void dieAphid(int& amountFood);
	void loseHpAphid(int damageHp, int& amountFood);
	void restoreHpAphid(int point);
	void Eat(Food& food);

	bool isAlive();
	int getHp() const;
	int getAge() const;

	void setPosition(Vector2f pos);
	void draw(RenderWindow& window) const;

private:
	int hpAphid, ageAphid;
	CircleShape shape;
};