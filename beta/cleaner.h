#ifndef CLEANER_H
#define CLEANER_H

#include <string>

class Anthill; // Предварительное объявление класса Anthill

class Cleaner {
private:
    Anthill* anthill;
    int age;
    int health;
    int cargoCapacity;
    int cargo;
    int maxDistance;
    std::string state; // Состояние муравья

public:
    Cleaner(Anthill* anthill, int age = 80, int health = 25);
    ~Cleaner();

    void work();
    void dailyUpdate();

    int getAge() const;
    int getHealth() const;

    void setAge(int age);
    void setHealth(int health);
};

#endif // CLEANER_H