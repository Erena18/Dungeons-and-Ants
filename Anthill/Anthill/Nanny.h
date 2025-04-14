#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Role.h"
#include "Ant.h"

using namespace std;

class Nanny : public Role
{
public:
	/*Nanny(Vec2 startPos, float speed = 50.0f)
		: position(startPos), speed(speed), 
		targetPosition(startPos), isMoving(false) {}

	Vec2 getPosition() const { return position; }*/
	virtual void Work() override;
	virtual void Eat(Ant& ant, Food& food) override;

	void update(float dt);
private:
	//Vec2 position;
	//Vec2 targetPosition;
	float speed;
	bool isMoving;
};