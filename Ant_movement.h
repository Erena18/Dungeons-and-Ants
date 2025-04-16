#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "Role.h"
#include "Informer.h"

using namespace std;
using namespace sf;

class Ant {
public:
    Ant();
    Ant(int initHp, int initAge, unique_ptr<Role> initRole);

    int getHp() const { return hp; }
    int getAge() const { return age; }

    bool isAlive() const;
    void growth();
    void updateRole();
    void loseHpEndDay();
    void loseHp(int damageHp);
    void restoreHp(int point);
    void die();

    void subscribeToInformer(Informer* informer);
    void unsubscribeFromInformer();

    // Виртуальные методы
    virtual void Work();
    virtual void Eat(Food& food);

    // Методы для отрисовки и позиционирования
    void draw(RenderWindow& window);
    void setPosition(Vector2f pos);

    // Метод для движения
    void move();

private:
    int hp, age;
    unique_ptr<Role> role;
    Informer* currentInformer = nullptr;

    CircleShape shape;
    Vector2f position;

    // Дополнительные переменные для движения
    Vector2f velocity;       // Скорость движения
    Vector2f target;         // Цель движения
    bool has_target = false; // Флаг наличия цели
    float speed = 2.0f;      // Скорость муравья
};