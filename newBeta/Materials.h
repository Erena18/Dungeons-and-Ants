// Materials.h
#ifndef MATERIALS_H
#define MATERIALS_H

#include "MaterialItem.h"
#include <vector>
#include "CentralWarehouse.h"

class Materials {
public:
    Materials();

    void addMaterial(int amount);
    int consume(int amount);
    int getAmount() const;
    int getTotalAmount() const;
    void use(int amount);
    void dailyUpdate(); // Увеличивает возраст материалов и удаляет испорченные

private:
    std::vector<MaterialItem> materialItems;
    int amount;
};

#endif // MATERIALS_H