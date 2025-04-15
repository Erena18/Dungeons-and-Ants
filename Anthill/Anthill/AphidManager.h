#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <iostream>
#include "Aphid.h"
#include "PastureZone.h"

using namespace std;
using namespace sf;

class AphidManager
{
public:
    void add(Vector2f position);
    void update(PastureZone& pasture, int& food);
    void draw(RenderWindow& window);

private:
    std::vector<unique_ptr<Aphid>> aphids;
    void removeDead();
};