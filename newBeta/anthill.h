#ifndef ANTHILL_H
#define ANTHILL_H

#include "Ant.h"
#include "Food.h"
#include "InformerCollector.h"
#include "InformerCleaner.h"
#include <vector>
#include <memory>

class Anthill {
public:
    static Anthill& getInstance();

    void addAnt(std::unique_ptr<Ant> ant);
    void removeDeadAnts();
    void dailyUpdate();

    void addFoodSupply(int amount);

    Food& getFood() { return food; }

    // Доступ к информерам
    InformerCollector& getInformerCollector() { return informerCollector; }
    InformerCleaner& getInformerCleaner() { return informerCleaner; }

private:
    Anthill();

    std::vector<std::unique_ptr<Ant>> ants;
    Food food;

    // Информеры
    InformerCollector informerCollector;
    InformerCleaner informerCleaner;

    // Singleton
    static Anthill* instance;
};

#endif // ANTHILL_H