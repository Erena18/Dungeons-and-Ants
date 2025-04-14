#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Ant.h"

using namespace std;
using namespace sf;

Ant::Ant() : hp(100), age(0), role(nullptr)
{
	shape.setRadius(5.f);
	shape.setOrigin(5.f, 5.f);
	shape.setFillColor(Color::White);
}

Ant::Ant(int initHp, int initAge, unique_ptr<Role> initRole) :
	hp(initHp), age(initAge), role(move(initRole))
{
	shape.setRadius(5.f);
	shape.setOrigin(5.f, 5.f);
	if (dynamic_cast<Builder*>(role.get())) shape.setFillColor(sf::Color::Blue);
	else if (dynamic_cast<Collector*>(role.get())) shape.setFillColor(sf::Color::Green);
	else if (dynamic_cast<Child*>(role.get())) shape.setFillColor(sf::Color::Magenta);
	else if (dynamic_cast<Nanny*>(role.get())) shape.setFillColor(sf::Color::Cyan);
	else if (dynamic_cast<Soldier*>(role.get())) shape.setFillColor(sf::Color::Red);
	else shape.setFillColor(sf::Color::White);
}

void Ant::updateRole()
{
	if ((role != nullptr) && (dynamic_cast<Queen*>(role.get())))
	{
		return;
	}
	Informer* previousInformer = currentInformer;
	if (age < 20)
	{
		role = make_unique<Child>();
		return;
	}
	else if ((age >= 20) && (age < 39))
	{
		role = make_unique<Nanny>();
		NannyInformer* nannyInformer;
		nannyInformer->subscribe(role.get());
		currentInformer = nannyInformer;
		return;
	}
	else if ((age >= 40) && (age < 59))
	{
		rand();
		int check = rand() % 2;
		if (check == 0)
		{
			role = make_unique<Soldier>();
			SoldierInformer* soldierInformer;
			soldierInformer->subscribe(role.get());
			currentInformer = soldierInformer;
			return;
		}
		else
		{
			role = make_unique<Heardsant>();
			return;
		}
	}
	else if ((age >= 60) && (age < 79) && (dynamic_cast<Soldier*>(role.get())))
	{
		role = make_unique<Builder>(collectorInformer);
		return;
	}
	else if ((age >= 60) && (age < 79) && (dynamic_cast<Heardsant*>(role.get())))
	{
		role = make_unique<Collector>();
		CollectorInformer* collectorInformer;
		collectorInformer->subscribe(role.get());
		currentInformer = collectorInformer;
		return;
	}
	else if ((age >= 80) && (age < 100))
	{
		role = make_unique<Cleaner>();
		CleanerInformer* cleanerInformer;
		cleanerInformer->subscribe(role.get());
		currentInformer = cleanerInformer;
		return;
	}
	else if (age >= 100)
	{			
		currentInformer->unsubscribe(role.get());
		die();
		return;
	}
	if (previousInformer)
	{
		previousInformer->unsubscribe(role.get());
	}
}

void Ant::loseHpEndDay()
{
	hp -= rand() % 11;
	if (hp < 0)
	{
		die();
	}
}

void Ant::loseHp(int damageHp)
{
	hp -= damageHp;
	if (hp < 0)
	{
		die();
	}
}

void Ant::restoreHp(int point)
{
	hp += point;
	if (hp > 100)
	{
		hp = 100;
	}
}

bool Ant::isAlive() const
{
	return hp > 0;
}

void Ant::growth()
{
	age++;
	updateRole();
	if ((hp <= 0) || (age > 100))
	{
		die();
	}
}

void Ant::die()
{
	delete this;
}

void Ant::subscribeToInformer(Informer* informer)
{
	if (currentInformer) 
	{
		currentInformer->unsubscribe(role.get());
	}
	currentInformer = informer;
	if (currentInformer) 
	{
		currentInformer->subscribe(role.get());
	}
}

void Ant::unsubscribeFromInformer()
{
	if (currentInformer) 
	{
		currentInformer->unsubscribe(role.get());
		currentInformer = nullptr;
	}
}

void Ant::Work()
{
	if (role != nullptr)
	{
		role->Work();
	}
}

void Ant::Eat(Food& food)
{
	if (role != nullptr)
	{
		role->Eat(*this, food);
	}
}

void Ant::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Ant::setPosition(sf::Vector2f pos)
{
	position = pos;
	shape.setPosition(position);
}
