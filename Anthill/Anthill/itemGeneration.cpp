#include "itemGeneration.h"
#include "FoodItem.h"
#include <math.h>

itemGenerator::itemGenerator(GameDataRef data)
{
	srand(static_cast<unsigned>(time(nullptr)));
}

void itemGenerator::update(float dt)
{
	if (generationClock.getElapsedTime().asSeconds() >= generateInterval)
	{
		generateFood(3, 150.f);        
		generateMaterials(2, 150.f);   
		generationClock.restart();
	}
}

Vector2f itemGenerator::getRandomPosition(float minDist)
{
	float x = 0.f, y = 0.f;

	while (sqrt(pow(x - SCREEN_WIDTH / 2, 2) + pow(y + SCREEN_HEIGHT / 2, 2)) < minDist)
	{
		x = static_cast<float>(rand() % SCREEN_WIDTH);
		y = static_cast<float>(rand() % SCREEN_HEIGHT);
	}

	return Vector2f(x, y);
}


void itemGenerator::generateFood(int count, float minDistFromCenter)
{
	for (int i = 0; i < count; i++)
	{
		FoodItem food;
		food.setPosition(getRandomPosition(minDistFromCenter));
		foodItems.push_back(food);
	}

}

void itemGenerator::generateMaterials(int count, float minDistFromCenter)
{
	for (int i = 0; i < count; i++)
	{
		MaterialItem material;
		material.setPosition(getRandomPosition(minDistFromCenter));
		materialsItems.push_back(material);
	}
}

void itemGenerator::drawItems(sf::RenderWindow& window)
{
	for (auto& food : foodItems)
		food.draw(window);
	for (auto& material : materialsItems)
		material.draw(window);
}