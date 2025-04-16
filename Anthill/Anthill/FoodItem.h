#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class FoodItem 
{
public:
    FoodItem(int amount = 10);

    int getAmount() const;
    int getAge() const;

    void increaseAge();
    bool isSpoiled() const;
    void reduceAmount(int amountToReduce);

    void setPosition(Vector2f pos);
    void draw(RenderWindow& window) const;

    Vector2f getPosition() const;
private:
    int amount;
    int age;
    CircleShape shape;
};