#include "Collector.h"
#include "Ant.h"
#include "Food.h"
#include "Anthill.h"
#include <iostream>
#include <cstdlib>

Collector::Collector()
    : cargoCapacity(3), cargo(0), healthLossPerDay(0) {
    // Подписываемся на информер
    informer = &Anthill::getInstance().getInformerCollector();
    informer->subscribe(this);
}

Collector::~Collector() {
    // Отписываемся от информера
    informer->unsubscribe(this);
}

void Collector::Work(Ant& ant) {
    // Реализация работы
    // ...
}

void Collector::Eat(Ant& ant, Food& food) {
    // Реализация еды
    // ...
}
