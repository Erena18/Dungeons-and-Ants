#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <memory>
#include <vector>

#include "GameData.h"
#include "Aphid.h"
#include "Builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collector.h"
#include "Heardsant.h"
#include "Nanny.h"
#include "Queen.h"
#include "Soldier.h"

#include "Role.h"
#include "Anthill.h"
#include "Food.h"
#include "Informers.h"

using namespace std;
using namespace sf;

class Ant
{
public:
	//Ant();
	explicit Ant(GameDataRef data);
	Ant(int initHp, int initAge, unique_ptr<Role> initRole);
	Ant(int initHp, int initAge, unique_ptr<Role> initRole, GameDataRef data);

	int getHp() const { return hp; }
	int getAge() const { return age; }
	bool isAlive() const { return alive; }
	
	void growth();
	void updateRole();
	void loseHpEndDay();
	void loseHp(int damageHp);
	void restoreHp(int point);
	void die();

	void setRole(std::unique_ptr<Role> newRole);

	void setPosition(const Vector2f& pos);

	void subscribeToInformer(Informer* informer);
	void unsubscribeFromInformer();

	Role* getRole() const { return role.get(); }
	
	void Work();
	void Eat(Food& food);
	void move();

	void draw(sf::RenderWindow& window);
	Vector2f getPosition() const;

	void setTarget(const Vector2f& t);
	Vector2f getTarget() const;
	void setRandomDirection();
	Vector2f getRandomDirection() const;

private:
	int hp = 100, age = 0;
	bool alive = true;
	GameDataRef _data;

	unique_ptr<Role> role;
	Informer* currentInformer = nullptr;

	CircleShape shape;
	Vector2f position;

	Vector2f targetPosition;
	Vector2f target = { 0.f, 0.f };
	Vector2f randomDirection = { 0.f, 0.f };
};