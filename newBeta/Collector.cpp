#include "Collector.h"
#include "Ant.h"
#include "Food.h"
#include "Anthill.h"
#include <iostream>
#include <cstdlib>

Collector::Collector()
    : cargoCapacity(3), cargo(0), healthLossPerDay(1 + rand() % 3) {
    // Подписываемся на информер
    informer = &Anthill::getInstance().getInformerCollector();
    informer->subscribe(this);
}

Collector::~Collector() {
    // Отписываемся от информера
    informer->unsubscribe(this);
}

void Collector::Work(Ant& ant) {
    // Ходит на разведку территорий, собирает съестные припасы и строительные материалы
    std::cout << "Collector is working.\n";

    int foundResources = rand() % 5; // Случайное количество найденных ресурсов (0-4)
    std::cout << "Collector found " << foundResources << " units of resources.\n";

    if (foundResources > 0) {
        if (foundResources <= cargoCapacity) {
            cargo = foundResources;
            std::cout << "Collector collects " << cargo << " units of resources.\n";
        }
        else {
            cargo = cargoCapacity;
            std::cout << "Collector collects maximum capacity of " << cargo << " units and calls for help.\n";
            // Вызываем на помощь других сборщиков
            informer->notifyCollectors("Collector needs help collecting resources!");
        }
        // Возвращаемся в поселение и добавляем ресурсы в общие запасы
        Anthill::getInstance().addFoodSupply(cargo);
        cargo = 0;
    }
    // Потеря здоровья за день работы
    ant.loseHp(healthLossPerDay);
}

void Collector::Eat(Ant& ant, Food& food) {
    int requiredFood = 15; // Потребляет 15 ед. еды
    if (food.getAmountFood() >= requiredFood) {
        food.consume(requiredFood);
        std::cout << "Collector eats " << requiredFood << " units of food.\n";
        // Восстанавливает здоровье после еды
        ant.restoreHp(15);
    }
    else {
        std::cout << "Not enough food for Collector to eat.\n";
        // Теряет здоровье без еды
        ant.loseHp(10); // Теряет 10 хп без еды
    }
}