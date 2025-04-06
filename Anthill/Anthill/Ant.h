#pragma once
#include "Role.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Ant
{
public:
	Ant();
	Ant(int initHp, int initAge, unique_ptr<Role> initRole);

	int getHp() const { return hp; }
	int getAge() const { return age; }

	void growth();
	void updateRole();
	void loseHpEndDay();
	void loseHp(int damageHp);
	void restoreHp(int point);
	void die();

	//Виртуальные
	void Work();
	void Eat(Ant& ant, int& food);

private:
	int hp, age;
	unique_ptr<Role> role;
};