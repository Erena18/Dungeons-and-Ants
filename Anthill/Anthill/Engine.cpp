#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Engine.h"
#include "Ant.h"

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
	}
}
