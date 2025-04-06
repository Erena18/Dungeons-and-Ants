// Building.cpp
#include "Building.h"

Building::Building(int capacity, int count, int constructionCost)
    : capacity(capacity), count(count), constructionCost(constructionCost) {
}

int Building::getCapacity() const {
    return capacity * count;
}

int Building::getCount() const {
    return count;
}

int Building::getConstructionCost() const {
    return constructionCost;
}