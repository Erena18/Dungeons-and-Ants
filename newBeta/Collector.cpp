#include "Collector.h"
#include "Ant.h"
#include "Food.h"
#include "Anthill.h"
#include <iostream>
#include <cstdlib>

Collector::Collector()
    : cargoCapacity(3), cargo(0), healthLossPerDay(1 + rand() % 3) {
    // ������������� �� ��������
    informer = &Anthill::getInstance().getInformerCollector();
    informer->subscribe(this);
}

Collector::~Collector() {
    // ������������ �� ���������
    informer->unsubscribe(this);
}

void Collector::Work(Ant& ant) {
    // ����� �� �������� ����������, �������� �������� ������� � ������������ ���������
    std::cout << "Collector is working.\n";

    int foundResources = rand() % 5; // ��������� ���������� ��������� �������� (0-4)
    std::cout << "Collector found " << foundResources << " units of resources.\n";

    if (foundResources > 0) {
        if (foundResources <= cargoCapacity) {
            cargo = foundResources;
            std::cout << "Collector collects " << cargo << " units of resources.\n";
        }
        else {
            cargo = cargoCapacity;
            std::cout << "Collector collects maximum capacity of " << cargo << " units and calls for help.\n";
            // �������� �� ������ ������ ���������
            informer->notifyCollectors("Collector needs help collecting resources!");
        }
        // ������������ � ��������� � ��������� ������� � ����� ������
        Anthill::getInstance().addFoodSupply(cargo);
        cargo = 0;
    }
    // ������ �������� �� ���� ������
    ant.loseHp(healthLossPerDay);
}

void Collector::Eat(Ant& ant, Food& food) {
    int requiredFood = 15; // ���������� 15 ��. ���
    if (food.getAmountFood() >= requiredFood) {
        food.consume(requiredFood);
        std::cout << "Collector eats " << requiredFood << " units of food.\n";
        // ��������������� �������� ����� ���
        ant.restoreHp(15);
    }
    else {
        std::cout << "Not enough food for Collector to eat.\n";
        // ������ �������� ��� ���
        ant.loseHp(10); // ������ 10 �� ��� ���
    }
}