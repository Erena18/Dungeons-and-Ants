// Ant.cpp
#include "Ant.h"
#include "Cleaner.h"
#include <memory>
#include "anthill.h"
#include "Collector.h"
#include "InformerCleaner.h" // Новое включение
#include "InformerCollector.h" // Новое включение
Ant::Ant(int initHp, int initAge, std::unique_ptr<Role> initRole)
    : hp(initHp), age(initAge), alive(true), role(std::move(initRole)) {
}

Ant::~Ant() {}

int Ant::getHp() const {
    return hp;
}

int Ant::getAge() const {
    return age;
}

bool Ant::isAlive() const {
    return alive;
}

void Ant::growth() {
    ++age;
    updateRole();
}

void Ant::Work() {
    if (alive) {
        role->Work(*this);
    }
}

void Ant::Eat(Food& food) {
    if (alive) {
        role->Eat(*this, food);
    }
}

void Ant::loseHp(int damageHp) {
    hp -= damageHp;
    if (hp <= 0) {
        die();
    }
}

void Ant::restoreHp(int points) {
    hp += points;
}

void Ant::die() {
    alive = false;
    hp = 0;
}

void Ant::updateRole() {
    if (age >= 80 && typeid(*role) == typeid(Collector)) {
        role = std::make_unique<Cleaner>();
    }
}