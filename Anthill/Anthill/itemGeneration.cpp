#include "itemGeneration.h"
#include "FoodItem.h"
#include <math.h>

itemGenerator::itemGenerator(GameDataRef data)
{
	srand(static_cast<unsigned>(time(nullptr)));
}

void itemGenerator::update(float dt, std::vector<FoodItem>& foodItems, std::vector<MaterialItem>& materialItems)
{
	if (generationClock.getElapsedTime().asSeconds() >= generateInterval)
	{
		generateFood(5, 80.f, foodItems);
		generateMaterials(3, 80.f, materialItems);
		generationClock.restart();
	}
}

void itemGenerator::generateFood(int count, float minDistFromCenter, std::vector<FoodItem>& foodItems)
{
	for (int i = 0; i < count; i++)
	{
		FoodItem food;
		food.setPosition(getRandomPosition(minDistFromCenter));
		foodItems.push_back(food);
	}
}

void itemGenerator::generateMaterials(int count, float minDistFromCenter, std::vector<MaterialItem>& materialsItems)
{
	for (int i = 0; i < count; i++)
	{
		MaterialItem material;
		material.setPosition(getRandomPosition(minDistFromCenter));
		materialsItems.push_back(material);
	}
}

Vector2f itemGenerator::getRandomPosition(float minDist)
{
	FloatRect anthillZone(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 100, 200, 200);
	FloatRect dumpZone(100, 100, 100, 100); // замените на реальные координаты свалки
	FloatRect pastureZone(1000.f, 600.f, 250.f, 150.f); // размеры пастбища

	Vector2f pos;
	int maxAttempts = 200;
	int attempts = 0;

	do {
		pos.x = static_cast<float>(rand() % SCREEN_WIDTH);
		pos.y = static_cast<float>(rand() % SCREEN_HEIGHT);
		attempts++;

		// Повторять, пока попадает в запрещённые зоны
	} while ((anthillZone.contains(pos) ||
		dumpZone.contains(pos) ||
		pastureZone.contains(pos)) && attempts < maxAttempts);

	return pos;
}


/*void itemGenerator::generateFood(int count, float minDistFromCenter)
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
}*/

void itemGenerator::drawItems(sf::RenderWindow& window)
{
	for (auto& food : foodItems)
		food.draw(window);
	for (auto& material : materialsItems)
		material.draw(window);
}