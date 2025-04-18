#pragma once
#include <SFML/System.hpp>
#include <iostream>
#include <memory>
#include <vector>

#include "Role.h"
#include "Ant.h"
#include "Informers.h"
#include "MaterialsItem.h"
#include "FoodItem.h"
#include <cmath>

using namespace std;
using namespace sf;

class Ant;
class FoodItem;
class MaterialsItem;

class Collector : public Role 
{
public:
    explicit Collector(float gatherRadius = 80.f);

    void Work(Ant& ant) override;
    void Eat(Ant& ant, Food& food) override;
    void Move(Ant& ant) override;

    /*Collector(CollectorInformer* informer) : informer(informer) {}
    CollectorInformer* getInformer() const { return informer; }
    void setInformer(CollectorInformer* informer)
    {
        this->informer = informer;
    }*/

    void setFoodItems(vector<FoodItem>* foods);
    void setMaterialItems(vector<MaterialItem>* mats);
    void setHomePosition(const Vector2f& home);

private:
    float radius = 80.f;                            
    bool carrying = false;                  
    int carriedFood = 0;
    int carriedMaterials = 0;
    Vector2f homePos;                   
    vector<FoodItem>* foodItems = nullptr;
    vector<MaterialItem>* materialItems = nullptr;
    /*CollectorInformer* informer; */
};
