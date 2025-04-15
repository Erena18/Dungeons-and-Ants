#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Engine.h"
#include "Ant.h"
#include "PastureZone.h"

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

		_data->window.clear();

		pasture.draw(_data->window);

		_data->window.display();
	}
}
