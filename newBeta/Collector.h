// Collector.h
#ifndef COLLECTOR_H
#define COLLECTOR_H

#include "Role.h"
#include "InformerCollector.h"
#include <string>
#include <memory>

class Collector : public Role {
public:
    Collector();
    ~Collector();

    void Work(Ant& ant) override;
    void Eat(Ant& ant, Food& food) override;
    void receiveNotification(const std::string& message) override;

private:
    int cargoCapacity;          // ������������ ���������������� (3 �������)
    int healthLossPerDay;       // ������ �������� � ���� (1-3)
    InformerCollector* informer;

    bool helpRequested;         // ���� ������� ������
};

#endif // COLLECTOR_H