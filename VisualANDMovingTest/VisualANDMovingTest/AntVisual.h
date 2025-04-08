#pragma once
#include "AntLogic.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class AntVisual {
public:
    AntVisual(Vec2 startPos) : logic(startPos) {
        if (!texture.loadFromFile("ant.png")) {
            // ������ �������� � ����� ��������� ���������� ��� �������� �� ������
            throw std::runtime_error("�� ������� ��������� ant.png");
        }

        sprite.setTexture(texture);
        sprite.setScale(0.2f, 0.2f); // ��������� �����������, ���� ��� �������
        sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2); // ����� �������
    }

    /*AntVisual(Vec2 startPos) : logic(startPos) {
        shape.setRadius(4.0f);
        shape.setOrigin(4.0f, 4.0f);
        shape.setFillColor(sf::Color::Black);
    }*/

    void update(float dt, int width, int height);
    void draw(RenderWindow& window);

private:
    AntLogic logic;
    //CircleShape shape;
    Texture texture;
    Sprite sprite;
};