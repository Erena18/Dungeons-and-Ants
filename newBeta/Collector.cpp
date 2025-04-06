#include "Collector.h"
#include "Ant.h"
#include "Food.h"
#include "Anthill.h"
#include <iostream>
#include <cstdlib>

Collector::Collector()
    : cargoCapacity(3), cargo(0), healthLossPerDay(0) {
    // ������������� �� ��������
    informer = &Anthill::getInstance().getInformerCollector();
    informer->subscribe(this);
}

Collector::~Collector() {
    // ������������ �� ���������
    informer->unsubscribe(this);
}

void Collector::Work(Ant& ant) {
    // ���������� ������
    // ...
}

void Collector::Eat(Ant& ant, Food& food) {
    // ���������� ���
    // ...
}
