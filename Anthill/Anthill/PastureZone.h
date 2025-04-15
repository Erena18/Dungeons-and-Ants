#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "Aphid.h"
#include "Heardsant.h"

using namespace std;
using namespace sf;

// Пастбищная зона
class PastureZone : public Zone 
{
public:
    PastureZone(Vector2f position, Vector2f size);

    void draw(RenderWindow& window) const;
private:
    RectangleShape area;
};