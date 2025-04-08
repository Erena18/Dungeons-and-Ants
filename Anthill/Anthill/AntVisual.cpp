#include "AntLogic.h"
#include "AntVisual.h"
#include <SFML/Graphics.hpp>

using namespace std;

void AntVisual::update(float dt, int width, int height)
{
	logic.update(dt, width, height);
	Vec2 pos = logic.getPosition();
	sprite.setPosition(pos.getX(), pos.getY());

	// otvorot-povorot
	Vec2 velocity = logic.getVelocity();
	float angle = atan2(velocity.getY(), velocity.getX()) * 180.0f / 3.14159f;
	sprite.setRotation(angle);
}

void AntVisual::draw(RenderWindow& window) {
	window.draw(sprite);
}