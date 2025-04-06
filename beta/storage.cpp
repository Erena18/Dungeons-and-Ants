#include "Storage.h"
#include <iostream>
#include <algorithm>

// ������� ����� Storage
Storage::Storage(const std::string& name, int capacity)
    : name(name), capacity(capacity), currentLoad(0) {
}

Storage::~Storage() {
    // ������� ���
    for (Food* food : foodStorage) {
        delete food;
    }
    foodStorage.clear();

    // ������� ������
    for (Garbage* garbage : garbageStorage) {
        delete garbage;
    }
    garbageStorage.clear();
}

void Storage::addResource(int amount) {
    if (currentLoad + amount <= capacity) {
        currentLoad += amount;
    }
    else {
        // ��������� ������������ ������
        std::cout << "[" << name << "] Ne Vlezaet Uzhe na sklad" << std::endl;
    }
}

void Storage::removeResource(int amount) {
    if (currentLoad - amount >= 0) {
        currentLoad -= amount;
    }
    else {
        // ��������� �������� ��������
        std::cout << "[" << name << "] Net Resursov na sklade" << std::endl;
    }
}

void Storage::addFood(Food* food) {
    if (currentLoad + food->getQuantity() <= capacity) {
        foodStorage.push_back(food);
        currentLoad += food->getQuantity();
    }
    else {
        // ��������� ������������ ������
        std::cout << "[" << name << "] Food ne vlezaet" << std::endl;
        delete food;
    }
}

void Storage::removeFood(Food* food) {
    auto it = std::find(foodStorage.begin(), foodStorage.end(), food);
    if (it != foodStorage.end()) {
        currentLoad -= food->getQuantity();
        foodStorage.erase(it);
        delete food;
    }
    else {
        // ��� �� �������
        std::cout << "[" << name << "] Net food na sklade" << std::endl;
    }
}

Food* Storage::getFood() {
    if (!foodStorage.empty()) {
        return foodStorage.front();
    }
    return nullptr;
}

void Storage::addGarbage(Garbage* garbage) {
    if (currentLoad + garbage->getWeight() <= capacity) {
        garbageStorage.push_back(garbage);
        currentLoad += garbage->getWeight();
    }
    else {
        // ��������� ������������ ������
        std::cout << "[" << name << "] net mesta dlya musora" << std::endl;
        delete garbage;
    }
}

void Storage::removeGarbage(Garbage* garbage) {
    auto it = std::find(garbageStorage.begin(), garbageStorage.end(), garbage);
    if (it != garbageStorage.end()) {
        currentLoad -= garbage->getWeight();
        garbageStorage.erase(it);
        delete garbage;
    }
    else {
        // ����� �� ������
        std::cout << "[" << name << "] musor ne naiden na sklade" << std::endl;
    }
}

void Storage::update(const std::string& message) {
    std::cout << "[" << name << "] new message " << message << std::endl;
}

// CentralStorage
CentralStorage::CentralStorage(int capacity)
    : Storage("Central Storage", capacity) {
}

void CentralStorage::work() {
    // ������ ������ ������������ ���������
}

void CentralStorage::eat() {
    // ������ ����������� �������� ����������� ����������
}