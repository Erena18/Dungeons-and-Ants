#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Child.h"
#include "Queen.h"
#include "Builder.h"
#include "Cleaner.h"
#include "Soldier.h"
#include "Heardsant.h"
#include "Collector.h"

#include "Dimensions.h"
#include "AntLogic.h"

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Nanny : public Role
{
public:
	Nanny(Vec2 startPos, float speed = 50.0f)
		: position(startPos), speed(speed), 
		targetPosition(startPos), isMoving(false) {}

	Vec2 getPosition() const { return position; }
	virtual void Work() override;
	virtual void Eat(Ant& ant, Food& food) override;

	void update(float dt);
private:
	Vec2 position;
	Vec2 targetPosition;
	float speed;
	bool isMoving;
};