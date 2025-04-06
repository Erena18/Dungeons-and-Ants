#include "Ant.h"
#include "InformerAnt.h"
#include "Collector.h"
#include "Cleaner.h"
#include <iostream>

Ant::Ant(int initHp, int initAge, std::unique_ptr<Role> initRole)
    : hp(initHp), age(initAge), role(std::move(initRole)), informer(std::make_unique<InformerAnt>()) {
}
void Ant::growth() {
    age++;
    updateRole();
}
Ant::~Ant() {
    // ���������� �� ���������
}
void Ant::updateRole() {
    // ���������� ���� ������� � ����������� �� ��������
    if (age >= 80 && dynamic_cast<Collector*>(role.get()) != nullptr) {
        // ������ ���� �� ��������
        role = std::make_unique<Cleaner>();
        hp = 25; // �������� ��������
        informer->report("Collector has become a Cleaner.");
    }
}

void Ant::loseHpEndDay() {
    // ������ �������� � ����� ��� (1-3 ��.)
    int healthLoss = rand() % 3 + 1;
    loseHp(healthLoss);
}

void Ant::loseHp(int damageHp) {
    hp -= damageHp;
    if (hp <= 0) {
        die();
    }
}

void Ant::restoreHp(int point) {
    hp += point;
    // ������������ �������� ������� �� ����
    if (dynamic_cast<Collector*>(role.get()) != nullptr && hp > 40) {
        hp = 40;
    }
    else if (dynamic_cast<Cleaner*>(role.get()) != nullptr && hp > 25) {
        hp = 25;
    }
}

void Ant::die() {
    hp = 0;
    informer->report("An ant has died.");
}

void Ant::Work() {
    if (role && hp > 0) {
        role->Work(*this);
    }
}

void Ant::Eat(Food& food) {
    if (role && hp > 0) {
        role->Eat(*this, food);
    }
}