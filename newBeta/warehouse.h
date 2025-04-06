// Warehouse.h
#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Building.h"

class Warehouse : public Building {
public:
    Warehouse();
    void dailyUpdate() override; 
};

#endif // WAREHOUSE_H