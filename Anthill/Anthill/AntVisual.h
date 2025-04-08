#pragma once
#include "AntLogic.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class AntVisual {
public:
    AntVisual(Vec2 startPos) : logic(startPos) {
        if (!texture.loadFromFile("ant.png")) {
            throw std::runtime_error("Не удалось загрузить ant.png");
        }

        sprite.setTexture(texture);
        sprite.setScale(0.1f, 0.1f);
        sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
        sprite.setPosition(startPos.getX(), startPos.getY());
    }

    void update(float dt, int width, int height);
    void draw(RenderWindow& window);

private:
    AntLogic logic;
    Texture texture;
    Sprite sprite;
};