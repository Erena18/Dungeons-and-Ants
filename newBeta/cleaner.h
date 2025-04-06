// Cleaner.h
#ifndef CLEANER_H
#define CLEANER_H

#include "Role.h"
#include "InformerCleaner.h"
#include <string>
#include <memory>

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
    InformerCleaner* informer;

    bool helpRequested;         // Флаг запроса помощи
};

#endif // CLEANER_H