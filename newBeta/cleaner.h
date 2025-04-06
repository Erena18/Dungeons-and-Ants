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

    void receiveNotification(const std::string& message) override; // Добавляем override

private:
    int maxDistance;
    int healthLossPerDay;
    InformerCleaner* informer;
};

#endif // CLEANER_H