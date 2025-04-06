#include "Garbage.h"

Garbage::Garbage(const std::string& type, int weight)
    : type(type), weight(weight) {
}

std::string Garbage::getType() const {
    return type;
}

int Garbage::getWeight() const {
    return weight;
}

void Garbage::setWeight(int weight) {
    this->weight = weight;
}
