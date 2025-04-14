#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "Ant.h"
#include "Aphid.h"

using namespace std;

class Ant;
class Aphid;
class Anthill;

class Zone 
{
public:
    virtual ~Zone() = default;

    // Обновление состояния зоны
    virtual void update() = 0;
    virtual string getType() const = 0;
    virtual bool isEmpty() const { return false; }
    virtual void onAntEnter() = 0;
};

class ZoneManager 
{
public:
    static ZoneManager& getInstance();
    Zone* getCurrentZone(Ant& ant) { return currentZone; }
    Zone* getCurrentZoneaAphid(Aphid& aphid) { return currentZone; }
private:
    Zone* currentZone;
};