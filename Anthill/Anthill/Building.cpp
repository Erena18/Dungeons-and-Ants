#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Building.h"

using namespace std;

Building::Building(int capacity, int count, int constructionCost): capacity(capacity), count(count), constructionCost(constructionCost) {}

int Building::getCapacity()const
{
    return capacity * count;
}

int Building::getCount() const 
{
    return count;
}

int Building::getConstructionCost() const 
{
    return constructionCost;
}