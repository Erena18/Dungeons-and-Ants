#include "Cleaner.h"
#include "Ant.h"
#include "Food.h"
#include "Anthill.h"
#include <iostream>
#include <cstdlib>

Cleaner::Cleaner()
    : maxDistance(15 + rand() % 21), healthLossPerDay(0) {
    // Подписываемся на информер
    informer = &Anthill::getInstance().getInformerCleaner();
    informer->subscribe(this);
}

Cleaner::~Cleaner() {
    // Отписываемся от информера
    informer->unsubscribe(this);
}

void Cleaner::Work(Ant& ant) {
    // Реализация работы
    // ...
}

void Cleaner::Eat(Ant& ant, Food& food) {
    // Реализация еды
    // ...
}