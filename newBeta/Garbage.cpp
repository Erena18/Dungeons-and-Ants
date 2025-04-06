// Garbage.cpp
#include "Garbage.h"

Garbage::Garbage(Type type, int weight)
    : type(type), weight(weight) {
}

Garbage::Type Garbage::getType() const {
    return type;
}

int Garbage::getWeight() const {
    return weight;
}