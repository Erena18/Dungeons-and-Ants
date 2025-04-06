#include "Anthill.h"
#include "Collector.h"
#include "Cleaner.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Anthill& anthill = Anthill::getInstance();

    // Добавляем муравьев-собирателей
    for (int i = 0; i < 5; ++i) {
        auto collector = std::make_unique<Ant>(40, 60, std::make_unique<Collector>());
        anthill.addAnt(std::move(collector));
    }

    // Запускаем симуляцию на 30 дней
    for (int day = 1; day <= 30; ++day) {
        std::cout << "\nDay " << day << std::endl;
        anthill.dailyUpdate();
    }

    return 0;
}