#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <vector>
#include "Observer.h"
#include "Food.h"
#include "Garbage.h"

class Storage : public Observer {
protected:
    int capacity;
    int currentLoad;
    std::string name;

    // Хранение еды и мусора
    std::vector<Food*> foodStorage;
    std::vector<Garbage*> garbageStorage;

public:
    Storage(const std::string& name, int capacity);
    virtual ~Storage();

    virtual void work() = 0;
    virtual void eat() = 0;

    void addResource(int amount);
    void removeResource(int amount);

    void addFood(Food* food);
    void removeFood(Food* food);
    Food* getFood();

    void addGarbage(Garbage* garbage);
    void removeGarbage(Garbage* garbage);

    // Реализация паттерна Наблюдатель
    void update(const std::string& message) override;
};

class CentralStorage : public Storage {
public:
    CentralStorage(int capacity);
    void work() override;
    void eat() override;
};

#endif // STORAGE_H