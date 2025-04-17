#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <memory>
#include <vector>
#include <sstream>

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

using namespace std;
using namespace sf;

Vector2f getRandomPositionNearNest(const Vector2f& center, float radius = 40.f)
{
	float angle = static_cast<float>(rand()) / RAND_MAX * 2 * 3.1415926f;
	float dist = static_cast<float>(rand()) / RAND_MAX * radius;
	float x = center.x + cos(angle) * dist;
	float y = center.y + sin(angle) * dist;
	return { x, y };
}

Engine::Engine(int widht, int hight, string title)
{
	_data->window.create(sf::VideoMode(widht, hight),
		title, Style::Close | Style::Titlebar);
	this->Run();
}

void Engine::Run()
{
	int days = 0;
	Clock dayClock;

	Font font;
	if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
	}
	
	/*Text uiText;
	uiText.setFont(font);
	uiText.setCharacterSize(16);
	uiText.setFillColor(Color::Black);
	uiText.setPosition(10.f, SCREEN_HEIGHT - 200.f);*/

	vector<Text> textLines;

	RectangleShape panel;
	panel.setSize(Vector2f(250.f, 300.f));
	panel.setPosition(5.f, SCREEN_HEIGHT - 300.f);
	panel.setFillColor(Color(0, 0, 0, 100));

	float newTime, frameTime, interpolation;
	float currentTime = this->_clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	
	PastureZone pasture({ 1000.f, 600.f }, { 250.f, 150.f });
	itemGenerator generator(_data);
	Anthill& anthill = Anthill::getInstance(_data);	
	anthill.spawnAnthill(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);


	auto addAnts = [&](auto rolePtr) {
		for (int i = 0; i < 3; ++i) {
			auto ant = make_unique<Ant>(_data);
			Vector2f spawnPos = getRandomPositionNearNest(anthill.getCenter());
			ant->setPosition(spawnPos);
			ant->setTarget(spawnPos);
			ant->setRole(make_unique<remove_pointer_t<decltype(rolePtr)>>());
			anthill.addAnt(move(ant));
		}
	};

	addAnts((Child*)nullptr);
	addAnts((Nanny*)nullptr);
	addAnts((Soldier*)nullptr);
	addAnts((Collector*)nullptr);
	addAnts((Builder*)nullptr);
	addAnts((Heardsant*)nullptr);
	addAnts((Cleaner*)nullptr);

	vector<FoodItem> foodItems;
	vector<MaterialItem> materialItems;

	auto queenAnt = make_unique<Ant>(_data);
	Vector2f spawnPos = getRandomPositionNearNest(anthill.getCenter());
	queenAnt->setPosition(spawnPos);
	queenAnt->setTarget(spawnPos);
	queenAnt->setRole(make_unique<Queen>());
	anthill.addAnt(move(queenAnt));

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

		generator.update(frameTime, foodItems, materialItems);

		anthill.getAphidManager().update(pasture, anthill.getFood());

		for (auto& ant : anthill.getAnts())
		{
			ant->Work();
			ant->move();
		}

		_data->window.clear(Color(220, 220, 220));

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

		for (const auto& item : foodItems)
			item.draw(_data->window);

		for (const auto& item : materialItems)
			item.draw(_data->window);

		anthill.drawAnthill();
		anthill.drawAllAnts(_data->window);


		int total = 0, child = 0, nanny = 0, soldier = 0, collector = 0;
		int builder = 0, heardsant = 0, cleaner = 0, queen = 0;

		for (auto& ant : anthill.getAnts()) {
			if (!ant->isAlive()) continue;
			total++;
			Role* role = ant->getRole();
			if (dynamic_cast<Child*>(role)) child++;
			else if (dynamic_cast<Nanny*>(role)) nanny++;
			else if (dynamic_cast<Soldier*>(role)) soldier++;
			else if (dynamic_cast<Collector*>(role)) collector++;
			else if (dynamic_cast<Builder*>(role)) builder++;
			else if (dynamic_cast<Heardsant*>(role)) heardsant++;
			else if (dynamic_cast<Cleaner*>(role)) cleaner++;
			else if (dynamic_cast<Queen*>(role)) queen++;
		}

		if (dayClock.getElapsedTime().asSeconds() >= 3.f) {
			days++;
			dayClock.restart();


			if (days % 2 == 0 && anthill.canAddAnt()) {
				int count = 1 + rand() % 3;
				for (int i = 0; i < count && anthill.canAddAnt(); ++i) {
					auto child = make_unique<Ant>(_data);
					child->setRole(make_unique<Child>());

					Vector2f offset(static_cast<float>((rand() % 61) - 30),
						static_cast<float>((rand() % 61) - 30));
					Vector2f spawnPos = anthill.getCenter() + offset;

					child->setPosition(spawnPos);
					child->setTarget(spawnPos);

					anthill.addAnt(move(child));
				}
			}
		}

		textLines.clear();

		auto makeLine = [&](const std::string& str, Color color, float offsetY) {
			Text line;
			line.setFont(font);
			line.setCharacterSize(16);
			line.setFillColor(color);
			line.setString(str);
			line.setPosition(10.f, SCREEN_HEIGHT - 280.f + offsetY);
			textLines.push_back(line);
			};

		int lineOffset = 0;
		makeLine("Day: " + std::to_string(days), Color::Black, lineOffset += 0);
		makeLine("Total ants: " + std::to_string(total), Color::Black, lineOffset += 20);
		makeLine("Children: " + std::to_string(child), Color::Magenta, lineOffset += 20);
		makeLine("Nannies: " + std::to_string(nanny), Color::Cyan, lineOffset += 20);
		makeLine("Soldiers: " + std::to_string(soldier), Color::Red, lineOffset += 20);
		makeLine("Collectors: " + std::to_string(collector), Color::Green, lineOffset += 20);
		makeLine("Builders: " + std::to_string(builder), Color::Blue, lineOffset += 20);
		makeLine("Heardsants: " + std::to_string(heardsant), Color(255, 165, 0), lineOffset += 20); // оранжевый
		makeLine("Cleaners: " + std::to_string(cleaner), Color(160, 160, 160), lineOffset += 20); // серый
		makeLine("Queen: " + std::to_string(queen), Color::Yellow, lineOffset += 20);
		makeLine("Food: " + std::to_string(anthill.getFood().getTotalAmount()), Color::Yellow, lineOffset += 20);
		makeLine("Materials: " + std::to_string(anthill.getMaterials().getTotalAmount()), Color(139, 69, 19), lineOffset += 20); // коричневый
		makeLine("Aphids: " + std::to_string(anthill.getAphidManager().getAphidsCount()), Color::Magenta, lineOffset += 20); // или другой цвет для тли

		for (const auto& line : textLines)
			_data->window.draw(line);

		/*ostringstream ss;
		ss << "Day: " << days << "\n";
		ss << "Total ants: " << total << "\n";
		ss << "Children: " << child << "\nNannies: " << nanny << "\nSoldiers: " << soldier << "\n";
		ss << "Collectors: " << collector << "\nBuilders: " << builder << "\n";
		ss << "Heardsants: " << heardsant << "\nCleaners: " << cleaner << "\n";
		ss << "Queen: " << queen << "\n";
		ss << "Food: " << anthill.getFood().getTotalAmount() << "\n";
		ss << "Materials: " << anthill.getMaterials().getTotalAmount() << "\n";*/

		//uiText.setString(ss.str());
		_data->window.draw(panel);
		//_data->window.draw(uiText);

		_data->window.display();
	}
}