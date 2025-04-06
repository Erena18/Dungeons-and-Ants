#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <string>

class Anthill; // Предварительное объявление класса Anthill

class Collector {
private:
    Anthill* anthill;
    int age;
    int health;
    int cargoCapacity;
    int cargo;
    std::string state; // Состояние муравья

public:
    Collector(Anthill* anthill, int age = 60, int health = 40);
    ~Collector();

    void work();
    void dailyUpdate();

    int getAge() const;
    int getHealth() const;

    void setAge(int age);
    void setHealth(int health);
};

#endif // COLLECTOR_H