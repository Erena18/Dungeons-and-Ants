// Materials.h
#ifndef MATERIALS_H
#define MATERIALS_H

#include "MaterialItem.h"
#include <vector>

class Materials {
public:
    Materials();

    void addMaterial(int amount);
    int consume(int amount);

    int getTotalAmount() const;
    void dailyUpdate(); // Увеличивает возраст материалов и удаляет испорченные

private:
    std::vector<MaterialItem> materialItems;
};

#endif // MATERIALS_H