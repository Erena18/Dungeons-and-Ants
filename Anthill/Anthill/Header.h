#pragma once
#include <iostream>
using namespace std;

class Role //абстрактный класс Role
{
public:
	virtual void Work() = 0; //чистая виртуальная функция «Work»
	virtual ~Role() {};
};

class Ant
{
public:
	Ant();
	Ant(int initHp, int initAge, int initExp, Role* initRole);

	// это для теста проги
	int getHp() const { return hp; }
	int getAge() const { return age; }
	Role* getRole() const { return role; }
	void incrementAge() { age++; }
	// но потом может пригодиться

	void setRole(Role* newRole);
	void updateRole();
	//void Work(); //это то, что делает муравей (в зависимости от роли)
	~Ant(); //надо дописать
private:
	int hp, age, exp;
	Role* role;
};

class Queen : public Role
{
public:
	void Work(); //муравей делает, что положено
};

class Child : public Role
{
public:
	void Work(); //муравей делает, что положено
};

class Nanny : public Role
{
public:
	void Work(); //муравей делает, что положено
};

class Soldier : public Role
{
public:
	void Work(); //муравей делает, что положено
};

class Heardsant : public Role //пастух :)
{
public:
	void Work(); //муравей делает, что положено
};

class Collector : public Role
{
public:
	void Work(); //муравей делает, что положено
};

class Builder : public Role
{
public:
	void Work(); //муравей делает, что положено
};

class Cleaner : public Role
{
public:
	void Work(); //муравей делает, что положено
};

