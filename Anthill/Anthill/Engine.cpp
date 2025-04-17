/*#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <vector>

#include "GameData.h"
#include "Engine.h"
#include "Ant.h"
#include "Anthill.h"
#include "PastureZone.h"
#include "AphidManager.h"
#include "Heardsant.h"
#include "Collector.h"
#include "Soldier.h"
#include "Cleaner.h"
#include "FoodItem.h"
#include "MaterialsItem.h"

using namespace sf;

Engine::Engine(int widht, int hight, std::string title)
{
	_data->window.create(sf::VideoMode(widht, hight),
		title, Style::Close | Style::Titlebar);
	this->Run();
}

void Engine::Run()
{
	float newTime, frameTime, interpolation;
	float currentTime = this->_clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	PastureZone pasture({ 1000.f, 600.f }, { 250.f, 150.f });
	itemGenerator generator(_data);

	Anthill& anthill = Anthill::getInstance(_data);
	anthill.spawnAnthill(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	vector<FoodItem> foodItems;
	vector<MaterialItem> materialItems;

	auto collectorRole = make_unique<Collector>(10.f);
	collectorRole->setFoodItems(&foodItems);
	collectorRole->setMaterialItems(&materialItems);
	collectorRole->setHomePosition(anthill.getCenter());

	auto collectorAnt = make_unique<Ant>(_data);
	collectorAnt->setPosition(anthill.getCenter());
	collectorAnt->setRole(move(collectorRole));
	anthill.addAnt(move(collectorAnt));

	auto soldierRole = make_unique<Soldier>();
	auto soldierAnt = make_unique<Ant>(_data);
	soldierAnt->setPosition(anthill.getCenter());
	soldierAnt->setRole(move(soldierRole));
	anthill.addAnt(move(soldierAnt));

	auto antPtr = make_unique<Ant>(_data);
	antPtr->setPosition(anthill.getCenter());
	antPtr->setRole(move(collectorRole));

	AphidManager aphidManager;

	auto heardsantRole = make_unique<Heardsant>();
	auto antHeardsant = make_unique<Ant>(_data);
	antHeardsant->setPosition(anthill.getCenter());
	antHeardsant->setRole(move(heardsantRole));
	anthill.addAnt(move(antHeardsant));

	anthill.addAnt(move(antPtr));

	while (this->_data->window.isOpen())
	{
		newTime = this->_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;
		

		if (frameTime > 0.25f)
			frameTime = 0.25f;

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt)
		{
			accumulator -= dt;
		}
		interpolation = accumulator / dt;
		generator.update(frameTime);

		for (auto& ant : anthill.getAnts())
		{
			ant->Work();
			ant->move();
		}

		_data->window.clear();

		pasture.draw(_data->window);
		GarbageManager::getInstance().draw(_data->window);

		anthill.getFood().drawAll(_data->window);
		anthill.getMaterials().drawAllMaterials(_data->window);

		for (auto& ant : anthill.getAnts())
		{
			if (auto* cleaner = dynamic_cast<Cleaner*>(ant->getRole()))
			{
				cleaner->drawDump(_data->window);
			}
		}

		auto collectorRole = make_unique<Collector>();
		collectorRole->setFoodItems(&foodItems);
		collectorRole->setMaterialItems(&materialItems);
		collectorRole->setHomePosition(anthill.getCenter());

		anthill.drawAnthill();
		anthill.drawAllAnts(_data->window);

		_data->window.display();
	}
}
*/
//#include <SFML/Audio.hpp>

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "GameData.h"
#include "Engine.h"
#include "Ant.h"
#include "Anthill.h"
#include "PastureZone.h"
#include "AphidManager.h"
#include "Heardsant.h"
#include "Collector.h"
#include "Soldier.h"
#include "Cleaner.h"
#include "FoodItem.h"
#include "MaterialsItem.h"

using namespace sf;

Engine::Engine(int widht, int hight, std::string title)
{
	_data->window.create(sf::VideoMode(widht, hight),
		title, Style::Close | Style::Titlebar);
	this->Run();
}

void Engine::Run()
{
	float newTime, frameTime, interpolation;
	float currentTime = this->_clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	
	PastureZone pasture({ 1000.f, 600.f }, { 250.f, 150.f });
	itemGenerator generator(_data);
	Anthill& anthill = Anthill::getInstance(_data);
	anthill.spawnAnthill(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);


	vector<FoodItem> foodItems;
	vector<MaterialItem> materialItems;

	auto collectorRole = make_unique<Collector>(10.f);
	collectorRole->setFoodItems(&foodItems);
	collectorRole->setMaterialItems(&materialItems);
	collectorRole->setHomePosition(anthill.getCenter());

	auto collectorAnt = make_unique<Ant>(_data);
	collectorAnt->setPosition(anthill.getCenter());
	collectorAnt->setRole(move(collectorRole));
	anthill.addAnt(move(collectorAnt));


	auto soldierRole = make_unique<Soldier>();
	auto soldierAnt = make_unique<Ant>(_data);
	soldierAnt->setPosition(anthill.getCenter());
	soldierAnt->setRole(move(soldierRole));
	anthill.addAnt(move(soldierAnt));


	auto heardsantRole = make_unique<Heardsant>();
	auto antHeardsant = make_unique<Ant>(_data);
	antHeardsant->setPosition(anthill.getCenter());
	antHeardsant->setRole(move(heardsantRole));
	anthill.addAnt(move(antHeardsant));

	while (_data->window.isOpen())
	{
		newTime = _clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;
		if (frameTime > 0.25f) frameTime = 0.25f;
		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt) {
			accumulator -= dt;
		}
		interpolation = accumulator / dt;

		generator.update(frameTime);

		anthill.getAphidManager().update(pasture, anthill.getFood());

		for (auto& ant : anthill.getAnts())
		{
			ant->Work();
			ant->move();
		}

		_data->window.clear();

		pasture.draw(_data->window);
		GarbageManager::getInstance().draw(_data->window);
		anthill.getFood().drawAll(_data->window);
		anthill.getMaterials().drawAllMaterials(_data->window);
		anthill.getAphidManager().draw(_data->window); 

		
		for (auto& ant : anthill.getAnts())
		{
			if (auto* cleaner = dynamic_cast<Cleaner*>(ant->getRole()))
			{
				cleaner->drawDump(_data->window);
			}
		}

		anthill.drawAnthill();
		anthill.drawAllAnts(_data->window);

		_data->window.display();
	}
}