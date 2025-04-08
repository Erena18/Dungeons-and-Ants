#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Nanny.h"
#include "Child.h"
#include "Queen.h"
#include "Builder.h"
#include "Soldier.h"
#include "Heardsant.h"
#include "Collector.h"

#include "Food.h"
#include "FoodItem.h"
#include "Anthill.h"

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

/*class Cleaner : public Role
{
public:
	virtual void Work() override
	{
		cout << "уборщик Работает" << endl;
	}
	virtual void Eat(Ant& ant, int& food) override;
};*/

class Cleaner : public Role {
public:
    Cleaner();
    ~Cleaner();

    void Work(Ant& ant) override;
    virtual void Eat(Ant& ant, Food& food) override;
    void receiveNotification(const std::string& message) override;

private:
    int maxDistance;            // Максимальное расстояние (15-35)
    int healthLossPerDay;       // Потеря здоровья в день (1-3)
    InformerCleaner* informer;

    bool helpRequested;         // Флаг запроса помощи
};