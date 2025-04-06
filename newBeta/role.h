#ifndef ROLE_H
#define ROLE_H

#include <memory>
#include <string>

class Ant;
class Food;

class Role {
public:
    virtual void Work(Ant& ant) = 0;
    virtual void Eat(Ant& ant, Food& food) = 0;
    virtual void receiveNotification(const std::string& message) {} // Добавляем эту строку
    virtual ~Role() {};
};

#endif // ROLE_H