#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include <vector>

#include "Food.h"
#include "PastureZone.h"

using namespace std;
using namespace sf;

class Aphid
{
public:
	Aphid();

	void growthAphid(Food& food);
	void dieAphid(Food& food);
	void loseHpAphid(int damageHp, Food& food);
	void restoreHpAphid(int point);
	void Eat(Food& food);

	void update(PastureZone& pasture);
	bool isAlive() const;
	int getHp() const;
	int getAge() const;
	Vector2f getPosition() const;

	void setPosition(Vector2f pos);
	void draw(RenderWindow& window) const;

private:
	int hpAphid, ageAphid;
	CircleShape shape;

	Vector2f homePosition;
	bool isOnPasture = false;

	Clock behaviourClock;
	float pastureInterval = 30.f + rand() % 20;
};