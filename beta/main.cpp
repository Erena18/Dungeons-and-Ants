#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Anthill.h"
#include "Collector.h"
#include "Cleaner.h"

int main() {
    // Инициализация генератора случайных чисел
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Создание муравейника
    Anthill anthill("Anthill #1");

    // Добавление сборщиков
    for (int i = 0; i < 5; ++i) {
        Collector* collector = new Collector(&anthill);
        anthill.addCollector(collector);
    }

    // Моделирование работы муравейника в течение 30 дней
    for (int day = 1; day <= 30; ++day) {
        std::cout << "\nDay " << day << ":\n";
        anthill.dailyUpdate();

        // На 10-й день пытаемся построить новый склад
        if (day == 10) {
            std::cout << "Attempting to build a new warehouse...\n";
            anthill.buildWarehouse();
        }

        // На 20-й день пытаемся расширить центральный склад
        if (day == 20) {
            std::cout << "Attempting to expand the central warehouse...\n";
            anthill.expandCentralWarehouse();
        }
    }

    return 0;
}