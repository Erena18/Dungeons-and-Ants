#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

using namespace std;
using namespace sf;

class Garbage 
{
public:
    enum class Type 
    {
        RottenFood,
        RottenMaterial,
        Corpse
    };
    Garbage(Type type, int weight);
    Type getType() const;
    int getWeight() const;

    void setPosition(Vector2f pos);
    void draw(RenderWindow& window) const;

private:
    Type type;
    int weight;

    CircleShape shape;
    Vector2f position;
};