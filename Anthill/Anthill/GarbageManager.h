#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Garbage.h"

using namespace std;
using namespace sf;

class GarbageManager 
{
public:
    static GarbageManager& getInstance();

    void addGarbage(Garbage::Type type, int weight);
    void removeGarbage(int index);

    const vector<Garbage>& getGarbageList() const;
    void draw(RenderWindow& window);
private:
    GarbageManager() {}
    vector<Garbage> garbageList;
};