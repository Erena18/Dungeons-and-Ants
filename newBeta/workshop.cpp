// Workshop.cpp
#include "Workshop.h"
#include "Anthill.h"
#include <cstdlib>

Workshop::Workshop()
    : Building(150, 1, 75) {
}

void Workshop::dailyUpdate() {
    // Производство материалов
    int materialsProduced = rand() % 5 + 1; // Производим 1-5 ед. материалов
    Anthill::getInstance().addMaterials(materialsProduced);
}