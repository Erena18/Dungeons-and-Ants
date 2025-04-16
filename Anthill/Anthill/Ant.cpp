#include "Ant.h"
#include "GameData.h"
#include "Role.h"
#include <utility>
#include <cstdlib>
#include <typeinfo>

Ant::Ant(GameDataRef data) : _data(data), hp(100), age(0),
alive(true), currentInformer(nullptr), shape(5.f)
{
	shape.setRadius(5.f);
	shape.setOrigin(5.f, 5.f);
	shape.setFillColor(Color::White);
}

Ant::Ant(int initHp, int initAge, unique_ptr<Role> initRole, GameDataRef data)
	: _data(data), hp(initHp), age(initAge), alive(true), role(std::move(initRole)), currentInformer(nullptr), shape(5.f)
{
	shape.setOrigin(5.f, 5.f);
	if (dynamic_cast<Builder*>(role.get()))        shape.setFillColor(Color::Blue);
	else if (dynamic_cast<Collector*>(role.get())) shape.setFillColor(Color::Green);
	else if (dynamic_cast<Child*>(role.get()))     shape.setFillColor(Color::Magenta);
	else if (dynamic_cast<Nanny*>(role.get()))     shape.setFillColor(Color::Cyan);
	else if (dynamic_cast<Soldier*>(role.get()))   shape.setFillColor(Color::Red);
	else                                           shape.setFillColor(Color::White);
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

void Ant::updateRole()
{
	if ((role != nullptr) && (dynamic_cast<Queen*>(role.get()))) {
		return;
	}

	Informer* oldInformer = currentInformer;
	unique_ptr<Role> newRole;
	Informer* newInformer = nullptr;

	if (age < 20)
	{
		newRole = make_unique<Child>();
	}
	else if (age < 40)
	{
		newRole = make_unique<Nanny>();
	}
	else if (age < 60)
	{
		rand();
		if (rand() % 2 == 0) {
			newRole = make_unique<Soldier>();
		}
		else {
			newRole = make_unique<Heardsant>();
		}
	}
	else if ((age < 80) && (dynamic_cast<Soldier*>(role.get())))
	{
		newRole = make_unique<Builder>();
	}
	else if ((age < 80) && (dynamic_cast<Heardsant*>(role.get())))
	{
		newRole = make_unique<Collector>();
	}
	else if (age < 100)
	{
		newRole = make_unique<Cleaner>();
	}
	else
	{			
		if (oldInformer && role) {
			oldInformer->unsubscribe(role.get());
		}
		die();
		return;
	}

	if (!role || typeid(*newRole) != typeid(*role)) {
		if (oldInformer && role) {
			oldInformer->unsubscribe(role.get());
		}

		role = std::move(newRole);

		/*if (role) {
			currentInformer = Anthill::getInstance().getInformer();

			if (currentInformer) {
				currentInformer->subscribe(role.get());
			}
		}*/

		if (dynamic_cast<Builder*>(role.get()))        shape.setFillColor(Color::Blue);
		else if (dynamic_cast<Collector*>(role.get())) shape.setFillColor(Color::Green);
		else if (dynamic_cast<Child*>(role.get()))     shape.setFillColor(Color::Magenta);
		else if (dynamic_cast<Nanny*>(role.get()))     shape.setFillColor(Color::Cyan);
		else if (dynamic_cast<Soldier*>(role.get()))   shape.setFillColor(Color::Red);
		else                                           shape.setFillColor(Color::White);
	}
}

void Ant::loseHpEndDay()
{
	hp -= rand() % 11;
	if (hp < 0)
		die();
}

void Ant::loseHp(int damageHp)
{
	hp -= damageHp;
	if (hp < 0)
		die();
}

void Ant::restoreHp(int point)
{
	hp += point;
	if (hp > 100)
		hp = 100;
}

void Ant::die()
{
	alive = false;
}

void Ant::setRole(std::unique_ptr<Role> newRole)
{
	if (currentInformer && role)
		currentInformer->unsubscribe(role.get());

	role = std::move(newRole);

	// Можно здесь обновить цвет муравья
	if (dynamic_cast<Builder*>(role.get()))        shape.setFillColor(Color::Blue);
	else if (dynamic_cast<Collector*>(role.get())) shape.setFillColor(Color::Green);
	else if (dynamic_cast<Child*>(role.get()))     shape.setFillColor(Color::Magenta);
	else if (dynamic_cast<Nanny*>(role.get()))     shape.setFillColor(Color::Cyan);
	else if (dynamic_cast<Soldier*>(role.get()))   shape.setFillColor(Color::Red);
	else                                           shape.setFillColor(Color::White);
}

void Ant::setPosition(const sf::Vector2f& pos)
{
	position = pos;
	shape.setPosition(pos);
}

void Ant::subscribeToInformer(Informer* informer) {
	if (currentInformer && role) {
		currentInformer->unsubscribe(role.get());
	}
	currentInformer = informer;
	if (currentInformer && role) {
		currentInformer->subscribe(role.get());
	}
}

void Ant::unsubscribeFromInformer() {
	if (currentInformer && role) {
		currentInformer->unsubscribe(role.get());
		currentInformer = nullptr;
	}
}

void Ant::Work()
{
	if (role != nullptr)
	{
		role->Work(*this);
	}
}

void Ant::Eat(Food& food)
{
	if (role != nullptr)
	{
		role->Eat(*this, food);
	}
}

void Ant::move()
{
	float speed = 1.5f;
	Vector2f dir = targetPosition - position;
	float distance = std::sqrt(dir.x * dir.x + dir.y * dir.y);

	if (distance > 1.f)
	{
		dir /= distance;
		position += dir * speed;
		shape.setPosition(position);
	}
}

void Ant::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

Vector2f Ant::getPosition() const
{
	return position;
}

void Ant::setTarget(const Vector2f& t)
{
	target = t;
}

Vector2f Ant::getTarget() const
{
	return target;
}

void Ant::setRandomDirection()
{
	float angle = static_cast<float>(rand()) / RAND_MAX * 2 * 3.1415926f;
	randomDirection = Vector2f(cos(angle), sin(angle));
}

Vector2f Ant::getRandomDirection() const
{
	return randomDirection;
}
