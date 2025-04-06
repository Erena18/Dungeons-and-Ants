#include "Ant.h"
#include "InformerAnt.h"
#include "Collector.h"
#include "Cleaner.h"
#include <iostream>

Ant::Ant(int initHp, int initAge, std::unique_ptr<Role> initRole)
    : hp(initHp), age(initAge), isAlive(true), role(std::move(initRole)), informer(std::make_unique<InformerAnt>()) {
}

Ant::~Ant() {
    // Деструктор
}

void Ant::growth() {
    ++age;
    std::cout << "Ant has grown to age " << age << ".\n";
    updateRole();
}

void Ant::updateRole() {
    if (age >= 80 && dynamic_cast<Collector*>(role.get())) {
        // Переходим с Собирателя на Уборщика
        std::cout << "Ant is changing role from Collector to Cleaner.\n";
        role = std::make_unique<Cleaner>();
    }
}

void Ant::loseHpEndDay() {
    // Возможно, потеря здоровья в конце дня
}

void Ant::loseHp(int damageHp) {
    hp -= damageHp;
    std::cout << "Ant loses " << damageHp << " HP. Current HP: " << hp << ".\n";
    if (hp <= 0) {
        die();
    }
}

void Ant::restoreHp(int point) {
    hp += point;
    std::cout << "Ant restores " << point << " HP. Current HP: " << hp << ".\n";
}

void Ant::die() {
    isAlive = false;
    hp = 0;
    std::cout << "Ant has died.\n";
}

void Ant::Work() {
    if (isAlive) {
        role->Work(*this);
    }
}

void Ant::Eat(Food& food) {
    if (isAlive) {
        role->Eat(*this, food);
    }
}