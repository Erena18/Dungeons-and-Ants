// Cleaner.h
#ifndef CLEANER_H
#define CLEANER_H
class Anthill; // Прямое объявление
class InformerCleaner; // Прямое объявление
#include "Role.h"
#include "InformerCleaner.h"
#include <string>

class Cleaner : public Role {
public:
    Cleaner();
    ~Cleaner();

    void Work(Ant& ant) override;
    void Eat(Ant& ant, Food& food) override;
    void receiveNotification(const std::string& message) override;

private:
    int maxDistance;            // Максимальное расстояние (15-35)
    int healthLossPerDay;       // Потеря здоровья в день (1-3)
    InformerCleaner* informer; // Теперь использует прямое объявление
};

#endif // CLEANER_H
