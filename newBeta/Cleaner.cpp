#include "Cleaner.h"
#include "Ant.h"
#include "Food.h"
#include "Anthill.h"
#include <iostream>
#include <cstdlib>

Cleaner::Cleaner()
    : healthLossPerDay(1 + rand() % 3) {
    // Устанавливаем максимальное расстояние (в зависимости от здоровья)
    maxDistance = 15 + rand() % 21; // 15-35
    // Подписываемся на информер
    informer = &Anthill::getInstance().getInformerCleaner();
    informer->subscribe(this);
}

Cleaner::~Cleaner() {
    // Отписываемся от информера
    informer->unsubscribe(this);
}

void Cleaner::Work(Ant& ant) {
    // Убирает мусор в муравейнике и уносит его на свалку
    std::cout << "Cleaner is working.\n";
    bool foundTrash = rand() % 2; // 50% шанс найти мусор

    if (foundTrash) {
        std::cout << "Cleaner found trash and removes it.\n";
        // Успешно убрал мусор
    }
    else {
        std::cout << "Cleaner did not find any trash.\n";
    }

    // Шанс найти опасную зону
    bool foundDangerousZone = (rand() % 100) < 10; // 10% шанс

    if (foundDangerousZone) {
        std::cout << "Cleaner found a dangerous zone and enters it.\n";
        // Заходит в опасную зону и умирает
        ant.die();
        return;
    }

    // Потеря здоровья за день работы
    ant.loseHp(healthLossPerDay);

    // Проверка здоровья
    if (ant.getHp() <= 5) {
        std::cout << "Cleaner's health is low and goes outside to die.\n";
        ant.die();
    }
}

void Cleaner::Eat(Ant& ant, Food& food) {
    int requiredFood = 10 + rand() % 6; // Потребляет 10-15 ед. еды
    if (food.getAmountFood() >= requiredFood) {
        food.consume(requiredFood);
        std::cout << "Cleaner eats " << requiredFood << " units of food.\n";
        // Восстанавливает здоровье после еды
        ant.restoreHp(15);
    }
    else {
        std::cout << "Not enough food for Cleaner to eat.\n";
        // Теряет здоровье без еды
        ant.loseHp(10); // Теряет 10 хп без еды
    }
}
