// CentralWarehouse.h
#ifndef CENTRALWAREHOUSE_H
#define CENTRALWAREHOUSE_H

#include "Building.h"

class CentralWarehouse : public Building {
public:
    CentralWarehouse();
    void dailyUpdate() override;
    void extend(int additionalCapacity, int cost);

private:
    int extensionCostPer50Units;
};

#endif // CENTRALWAREHOUSE_H