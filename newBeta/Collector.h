#ifndef COLLECTOR_H
#define COLLECTOR_H

#include "Role.h"
#include "InformerCollector.h"

class Collector : public Role {
public:
    Collector();
    ~Collector();

    virtual void Work(Ant& ant) override;
    virtual void Eat(Ant& ant, Food& food) override;

    void receiveNotification(const std::string& message) override;

private:
    int cargoCapacity;          // Максимальная грузоподъемность (3 единицы)
    int cargo;                  // Текущий груз
    int healthLossPerDay;       // Потеря здоровья в день (1-3)
    InformerCollector* informer;
};

#endif // COLLECTOR_H