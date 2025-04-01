#pragma once
#include <iostream>
using namespace std;

class Role //����������� ����� Role
{
public:
	virtual void Work() = 0; //������ ����������� ������� �Work�
	virtual ~Role() {};
};

class Ant
{
public:
	Ant();
	Ant(int initHp, int initAge, int initExp, Role* initRole);

	// ��� ��� ����� �����
	int getHp() const { return hp; }
	int getAge() const { return age; }
	Role* getRole() const { return role; }
	void incrementAge() { age++; }
	// �� ����� ����� �����������

	void setRole(Role* newRole);
	void updateRole();
	//void Work(); //��� ��, ��� ������ ������� (� ����������� �� ����)
	~Ant(); //���� ��������
private:
	int hp, age, exp;
	Role* role;
};

class Queen : public Role
{
public:
	void Work(); //������� ������, ��� ��������
};

class Child : public Role
{
public:
	void Work(); //������� ������, ��� ��������
};

class Nanny : public Role
{
public:
	void Work(); //������� ������, ��� ��������
};

class Soldier : public Role
{
public:
	void Work(); //������� ������, ��� ��������
};

class Heardsant : public Role //������ :)
{
public:
	void Work(); //������� ������, ��� ��������
};

class Collector : public Role
{
public:
	void Work(); //������� ������, ��� ��������
};

class Builder : public Role
{
public:
	void Work(); //������� ������, ��� ��������
};

class Cleaner : public Role
{
public:
	void Work(); //������� ������, ��� ��������
};

