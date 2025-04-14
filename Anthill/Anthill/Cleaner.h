#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Role.h"
#include "Ant.h"

using namespace std;

class Cleaner : public Role
{
public:
    virtual void Work() override;
    virtual void Eat(Ant& ant, Food& food) override;
    Cleaner(CleanerInformer* informer) : informer(informer) {}
    CleanerInformer* getInformer() const { return informer; }
    void setInformer(CleanerInformer* informer)
    {
        this->informer = informer;
    }
private:
    int maxDistance;            // Максимальное расстояние (15-35)
    bool helpRequested;         // Флаг запроса помощи
    CleanerInformer* informer;
};