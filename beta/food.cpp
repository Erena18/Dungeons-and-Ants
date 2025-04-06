#include "Food.h"

Food::Food(const std::string& type, int quantity, bool isSpoiled)
    : type(type), quantity(quantity), isSpoiled(isSpoiled) {
}

void Food::spoil() {
    isSpoiled = true;
}

void Food::consume(int amount) {
    if (quantity >= amount) {
        quantity -= amount;
    }
    else {
        quantity = 0;
    }
}

std::string Food::getType() const {
    return type;
}

int Food::getQuantity() const {
    return quantity;
}

void Food::setQuantity(int quantity) {
    this->quantity = quantity;
}

bool Food::getIsSpoiled() const {
    return isSpoiled;
}