// main.cpp
#include "Anthill.h"
#include "Collector.h"
#include <cstdlib>
#include <ctime>
#include <memory>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Anthill& anthill = Anthill::getInstance();

    // Добавляем муравьев-собирателей (возраст от 60 до 79)
    for (int i = 0; i < 5; ++i) {
        int age = 60 + rand() % 20;
        auto collector = std::make_unique<Ant>(40, age, std::make_unique<Collector>());
        anthill.addAnt(std::move(collector));
    }
    // Расширение центрального склада
    anthill.getCentralWarehouse().extend(50, 130);
    // Запускаем симуляцию на 30 дней
    for (int day = 1; day <= 30; ++day) {
        anthill.dailyUpdate();
    }

    return 0;

}