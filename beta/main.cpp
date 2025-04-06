#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Anthill.h"
#include "Collector.h"
#include "Cleaner.h"
int main() {
    // Initialize random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Create the anthill
    Anthill anthill("Anthill #1");

    // Add collectors
    for (int i = 0; i < 5; ++i) {
        Collector* collector = new Collector(&anthill);
        anthill.addCollector(collector);
    }

    // Simulate the anthill operations for 50 days
    for (int day = 1; day <= 50; ++day) {
        std::cout << "\nDay " << day << ":\n";
        anthill.dailyUpdate();

        // Attempt to build a new warehouse on day 10
        if (day == 10) {
            std::cout << "Attempting to build a new warehouse...\n";
            anthill.buildWarehouse();
        }

        // Attempt to expand the central warehouse on day 20
        if (day == 20) {
            std::cout << "Attempting to expand the central warehouse...\n";
            anthill.expandCentralWarehouse();
        }
    }

    return 0;
}