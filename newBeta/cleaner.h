#ifndef CLEANER_H
#define CLEANER_H

#include "Role.h"
#include "InformerCleaner.h"

class Cleaner : public Role {
public:
    Cleaner();
    ~Cleaner();

    virtual void Work(Ant& ant) override;
    virtual void Eat(Ant& ant, Food& food) override;

    void receiveNotification(const std::string& message) override;

private:
    int maxDistance;            // Максимальное расстояние (15-35)
    int healthLossPerDay;       // Потеря здоровья в день (1-3)
    InformerCleaner* informer;
};

#endif // CLEANER_H