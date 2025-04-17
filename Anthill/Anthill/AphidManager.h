#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <iostream>
#include "Aphid.h"
#include "PastureZone.h"

using namespace std;
using namespace sf;

class PastureZone;

class AphidManager
{
public:
    void add(Vector2f position);
    void update(PastureZone& pasture, Food& food);
    void draw(RenderWindow& window);
    const vector<unique_ptr<Aphid>>& getAphids() const { return aphids; }
    int getAphidsCount() const { return aphids.size(); }
private:
    std::vector<unique_ptr<Aphid>> aphids;
    void removeDead();
};