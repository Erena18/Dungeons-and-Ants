#include "Materials.h"

Materials::Materials() : amount(0) {}

void Materials::addMaterial(int a) 
{
    materialsItems.emplace_back(a);
    amount += a;
}

void Materials::use(int u)
{
    int actuallyConsumed = consume(u);
    amount -= actuallyConsumed;         

    if (amount < 0) amount = 0;
}

int Materials::getAmount() const 
{
    return amount;
}

int Materials::consume(int need) 
{
    int consumed = 0;

    for (auto it = materialsItems.begin(); it != materialsItems.end() && need > 0;)
    {
        if (!it->isSpoiled()) 
        {
            int have = it->getAmount();
            int take = (have <= need) ? have : need;

            consumed += take;
            need -= take;

            if (take >= have)
            {
                it = materialsItems.erase(it);
            }
            else 
            {
                it->reduceAmount(take);
                ++it;
            }
        }
        else 
        {
            ++it;
        }
    }
    return consumed;
}

int Materials::getTotalAmount() const 
{
    int total = 0;
    for (const auto& item : materialsItems) 
    {
        if (!item.isSpoiled()) 
        {
            total += item.getAmount();
        }
    }
    return total;
}

void Materials::dailyUpdate() 
{
    for (auto it = materialsItems.begin(); it != materialsItems.end();) 
    {
        it->increaseAge();

        if (it->isSpoiled()) 
        {
            GarbageManager::getInstance().addGarbage(Garbage::Type::RottenMaterial, it->getAmount());
            it = materialsItems.erase(it);
        }
        else 
        {
            ++it;
        }
    }
}

void Materials::drawAllMaterials(RenderWindow& window)
{
    for (MaterialItem& item : materialsItems)
    {
        item.draw(window);
    }
}
