#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "GameData.h"
#include "MaterialsItem.h"
#include "FoodItem.h"
#include "Anthill.h"
#include "extraFiles.h"
//#include "Engine.h"

using namespace sf;
using namespace std;

class itemGenerator
{
public:
	itemGenerator(GameDataRef data);

    void update(float dt, vector<FoodItem>& foodItems, vector<MaterialItem>& materialItems);

    void generateFood(int count, float minDistFromCenter, vector<FoodItem>& target);
    void generateMaterials(int count, float minDistFromCenter, vector<MaterialItem>& target);

    void drawItems(sf::RenderWindow& window);

    const vector<FoodItem>& getFoodItems() const { return foodItems; }
    const vector<MaterialItem>& getMaterialsItems() const { return materialsItems; }

private:
    GameDataRef _data;

    Clock generationClock;
    float generateInterval = 3.0f;

    vector<FoodItem> foodItems;
    vector<MaterialItem> materialsItems;

    Vector2f getRandomPosition(float minDist);
};