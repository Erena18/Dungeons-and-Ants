#pragma once


#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

class Ant;
class Anthill;

class Building 
{
public:
    Building(int capacity, int count, int constructionCost);
    virtual ~Building() {}

    int getCapacity()const;
    int getCount() const;
    int getConstructionCost() const;

    virtual void dailyUpdate() = 0;

protected:
    int capacity;
    int count;
    int constructionCost;
};