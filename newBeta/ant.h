// Ant.h
#ifndef ANT_H
#define ANT_H

#include <memory>
#include "Role.h"
#include "Food.h"

class Ant {
public:
    Ant(int initHp, int initAge, std::unique_ptr<Role> initRole);
    ~Ant();

    int getHp() const;
    int getAge() const;
    bool isAlive() const;

    void growth();
    void Work();
    void Eat(Food& food);
    void loseHp(int damageHp);
    void restoreHp(int points);
    void die();

    void updateRole();

private:
    int hp;
    int age;
    bool alive;
    std::unique_ptr<Role> role;
};

#endif // ANT_H