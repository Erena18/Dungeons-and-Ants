#include "Collector.h"
#include "Anthill.h"

Collector::Collector(float gatherRadius) : radius(gatherRadius) {}

void Collector::setFoodItems(vector<FoodItem>* foods)
{
    foodItems = foods;
}

void Collector::setMaterialItems(vector<MaterialItem>* mats)
{
    materialItems = mats;
}

void Collector::setHomePosition(const Vector2f& home)
{
    homePos = home;
}

void Collector::Work(Ant& ant)
{
    Vector2f pos = ant.getPosition();

    if (!carrying) {
        if (foodItems) {
            for (auto it = foodItems->begin(); it != foodItems->end(); ++it) {
                Vector2f itemPos = it->getPosition();
                float dx = pos.x - itemPos.x, dy = pos.y - itemPos.y;
                if (sqrt(dx * dx + dy * dy) <= radius) {
                    int multiplier = 2 + rand() % 3;
                    carriedFood = it->getAmount() * multiplier;
                    foodItems->erase(it);
                    carrying = true;
                    ant.setTarget(homePos);
                    return;
                }
            }
        }

        if (materialItems) {
            for (auto it = materialItems->begin(); it != materialItems->end(); ++it) {
                Vector2f itemPos = it->getPosition();
                float dx = pos.x - itemPos.x, dy = pos.y - itemPos.y;
                if (sqrt(dx * dx + dy * dy) <= radius) {
                    int multiplier = 2 + rand() % 3;
                    carriedMaterials = it->getAmount() * multiplier;
                    materialItems->erase(it);
                    carrying = true;
                    ant.setTarget(homePos);
                    return;
                }
            }
        }

        Vector2f currentTarget = ant.getTarget();
        float dx = currentTarget.x - pos.x;
        float dy = currentTarget.y - pos.y;
        float dist = sqrt(dx * dx + dy * dy);

        if (dist < 5.f || currentTarget == Vector2f(0.f, 0.f)) {
            ant.setRandomDirection();
            Vector2f wanderTarget = pos + ant.getRandomDirection() * 100.f;
            ant.setTarget(wanderTarget);
        }

        ant.move();
    }
    else {
        float dx = pos.x - homePos.x, dy = pos.y - homePos.y;
        float dist = sqrt(dx * dx + dy * dy);
        if (dist <= radius) {
            Anthill::getInstance().addFood(carriedFood);
            Anthill::getInstance().addMaterials(carriedMaterials);
            carrying = false;
            carriedFood = carriedMaterials = 0;
            ant.setTarget(Vector2f(0.f, 0.f));
        }
        else {
            ant.setTarget(homePos);
            ant.move();
        }
    }
}


void Collector::Eat(Ant& ant, Food& food)
{
    int foodRequired = 10;
    int hpLossWithoutFood = 6;
    int hpRestoreAfterEating = 10;

    int consumed = food.consume(foodRequired);
    if (consumed > 0)
    {
        ant.restoreHp(hpRestoreAfterEating);
    }
    else
    {
        ant.loseHp(hpLossWithoutFood);
    }
}

void Collector::Move(Ant& ant)
{
	ant.move();
}
