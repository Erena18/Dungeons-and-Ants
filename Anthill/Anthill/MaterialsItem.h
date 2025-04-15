#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Materials.h"

using namespace std;
using namespace sf;

class MaterialItem 
{
public:
    MaterialItem(int amount = 10);

    int getAmount() const;
    int getAge() const;

    void increaseAge();
    bool isSpoiled() const;
    void reduceAmount(int amountToReduce);

    void setPosition(Vector2f pos);
    void draw(RenderWindow& window) const;

private:
    int amount;
    int age;
    CircleShape shape;
};