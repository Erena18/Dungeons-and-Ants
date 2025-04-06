// Role.h
#ifndef ROLE_H
#define ROLE_H

#include <string>

class Ant;
class Food;

class Role {
public:
    virtual ~Role() {}

    virtual void Work(Ant& ant) = 0;
    virtual void Eat(Ant& ant, Food& food) = 0;
    virtual void receiveNotification(const std::string& message) = 0;
};

#endif // ROLE_H