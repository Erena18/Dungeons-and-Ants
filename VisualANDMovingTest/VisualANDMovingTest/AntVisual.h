#pragma once
#include "AntLogic.h"
#include <SFML/Graphics.hpp>

class AntVisual {
private:
    AntLogic logic;
    sf::CircleShape shape;

public:
    AntVisual(Vec2 startPos) : logic(startPos) {
        shape.setRadius(4.0f);
        shape.setOrigin(4.0f, 4.0f);
        shape.setFillColor(sf::Color::Black);
    }

    void update(float dt, int width, int height) {
        logic.update(dt, width, height);
        Vec2 pos = logic.getPosition();
        shape.setPosition(pos.getX(), pos.getY());
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
};