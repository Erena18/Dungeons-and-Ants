// Cleaner.h
#ifndef CLEANER_H
#define CLEANER_H
class Anthill; // ������ ����������
class InformerCleaner; // ������ ����������
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
    int maxDistance;            // ������������ ���������� (15-35)
    int healthLossPerDay;       // ������ �������� � ���� (1-3)
    InformerCleaner* informer; // ������ ���������� ������ ����������
};

#endif // CLEANER_H
