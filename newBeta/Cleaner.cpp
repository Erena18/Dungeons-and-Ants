#include "Cleaner.h"
#include "Ant.h"
#include "Food.h"
#include "Anthill.h"
#include <iostream>
#include <cstdlib>

Cleaner::Cleaner()
    : healthLossPerDay(1 + rand() % 3) {
    // ������������� ������������ ���������� (� ����������� �� ��������)
    maxDistance = 15 + rand() % 21; // 15-35
    // ������������� �� ��������
    informer = &Anthill::getInstance().getInformerCleaner();
    informer->subscribe(this);
}

Cleaner::~Cleaner() {
    // ������������ �� ���������
    informer->unsubscribe(this);
}

void Cleaner::Work(Ant& ant) {
    // ������� ����� � ����������� � ������ ��� �� ������
    std::cout << "Cleaner is working.\n";
    bool foundTrash = rand() % 2; // 50% ���� ����� �����

    if (foundTrash) {
        std::cout << "Cleaner found trash and removes it.\n";
        // ������� ����� �����
    }
    else {
        std::cout << "Cleaner did not find any trash.\n";
    }

    // ���� ����� ������� ����
    bool foundDangerousZone = (rand() % 100) < 10; // 10% ����

    if (foundDangerousZone) {
        std::cout << "Cleaner found a dangerous zone and enters it.\n";
        // ������� � ������� ���� � �������
        ant.die();
        return;
    }

    // ������ �������� �� ���� ������
    ant.loseHp(healthLossPerDay);

    // �������� ��������
    if (ant.getHp() <= 5) {
        std::cout << "Cleaner's health is low and goes outside to die.\n";
        ant.die();
    }
}

void Cleaner::Eat(Ant& ant, Food& food) {
    int requiredFood = 10 + rand() % 6; // ���������� 10-15 ��. ���
    if (food.getAmountFood() >= requiredFood) {
        food.consume(requiredFood);
        std::cout << "Cleaner eats " << requiredFood << " units of food.\n";
        // ��������������� �������� ����� ���
        ant.restoreHp(15);
    }
    else {
        std::cout << "Not enough food for Cleaner to eat.\n";
        // ������ �������� ��� ���
        ant.loseHp(10); // ������ 10 �� ��� ���
    }
}
