#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include <vector>

#include "Role.h"
#include "Ant.h"
#include "Garbage.h"

using namespace std;
using namespace sf;

class Cleaner : public Role
{
public:
    Cleaner();
    void Work(Ant& ant) override;
    void Eat(Ant& ant, Food& food) override;
    void Move(Ant& ant) override;

    void drawDump(sf::RenderWindow& window);
    /*Cleaner(CleanerInformer* informer) : informer(informer) {}
    CleanerInformer* getInformer() const { return informer; }
    void setInformer(CleanerInformer* informer)
    {
        this->informer = informer;
    }*/
private:
    int maxDistance= 25;          
    bool helpRequested = false;
    Vector2f dumpPos;
    RectangleShape dumpArea;
    //CleanerInformer* informer;
};