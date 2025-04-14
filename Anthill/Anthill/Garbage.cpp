#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime>

#include "Garbage.h"

using namespace std;

Garbage::Garbage(Type type, int weight): type(type), weight(weight) {}

Garbage::Type Garbage::getType() const 
{
    return type;
}

int Garbage::getWeight() const 
{
    return weight;
}