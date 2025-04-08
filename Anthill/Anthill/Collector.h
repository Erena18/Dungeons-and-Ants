#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Nanny.h"
#include "Child.h"
#include "Queen.h"
#include "Builder.h"
#include "Cleaner.h"
#include "Soldier.h"
#include "Heardsant.h"

#include "Food.h"
#include "FoodItem.h"
#include "Anthill.h"

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

/*class Collector : public Role
{
public:
	virtual void Work() override
	{
		cout << "собиратель Работает" << endl;
	}
	virtual void Eat(Ant& ant, int& food) override;
};*/

class Collector : public Role {
public:
    Collector();
    ~Collector();

    void Work(Ant& ant) override;
    void Eat(Ant& ant, Food& food) override;
    void receiveNotification(const std::string& message) override;

private:
    int cargoCapacity;          // макс грузоподъем
    int healthLossPerDay;       //потера хп
    InformerCollector* informer;

    bool helpRequested;         // Флаг о помощи
};
