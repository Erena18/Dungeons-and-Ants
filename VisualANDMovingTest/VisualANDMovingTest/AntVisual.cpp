#include "AntLogic.h"
#include "AntVisual.h"
#include <SFML/Graphics.hpp>

//void AntVisual::update(float dt, int width, int height)
//{
//    logic.update(dt, width, height);
//    Vec2 pos = logic.getPosition();
//    shape.setPosition(pos.getX(), pos.getY());
//}

//void AntVisual::draw(sf::RenderWindow& window)
//{
//    window.draw(shape);
//}

void AntVisual::update(float dt, int width, int height)
{
	logic.update(dt, width, height);
	Vec2 pos = logic.getPosition();
	sprite.setPosition(pos.getX(), pos.getY());
}

void AntVisual::draw(RenderWindow& window)
{
	window.draw(sprite);
}
