#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Building.h"

using namespace std;

class Anthill;

class Warehouse : public Building 
{
public:
    Warehouse();
    void dailyUpdate() override;
    void extend(int additionalCapacity, int cost);

private:
    int extensionCostPer50Units;
};