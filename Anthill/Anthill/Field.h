#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

// ������� ����� ��� ���� ���
class Zone {
public:
    virtual ~Zone() = default;

    // ���������� ��������� ���� (For instance: �������������� �������� ��� ����������)
    virtual void update() = 0;

    // �������. ���� ����
    virtual std::string getType() const = 0;

    // �������� �������� ����
    virtual bool isEmpty() const { return false; }

    // ��� �����, ���� ������� ����� � ����
    virtual void onAntEnter() = 0;
};

// ������ ����
class EmptyZone : public Zone {

public:
    std::string getType() const override { return "Empty"; }

    bool isEmpty() const override { return true; }

    void update() override {
        ++daysSinceLastUpdate;
        if (daysSinceLastUpdate >= 50) { //� �� 50 ���� ��������, ������� ���� 50 ���� � �����
            // ���� ����������� � ���������� ����� �� ���� ��������� ���
            //std::cout << "Empty zone has been refreshed!" << std::endl;
            daysSinceLastUpdate = 0;
        }
    }

    void onAntEnter() override {
        //std::cout << "An ant entered an empty zone." << std::endl;

    }

private:
    int daysSinceLastUpdate = 0;
};

// �������� ����
class FoodZone : public Zone {

public:
    FoodZone(int initialCapacity) : capacity(initialCapacity) {}

    std::string getType() const override { return "Food"; }

    void update() override {
        if (capacity > 0 && capacity < 10) {
            ++capacity; // �������������� ����������� ��� � 15-20 ����
            //std::cout << "Food zone capacity increased to " << capacity << "." << std::endl;
        }
    }

    void onAntEnter() override {
        if (capacity > 0) {
            --capacity;
            //std::cout << "An ant collected food. Remaining capacity: " << capacity << "." << std::endl;
        }
        else {
            //std::cout << "No food left in this zone." << std::endl;
        }
    }

private:
    int capacity; // ����������� ���

};

// ������������ ����
class MaterialZone : public Zone {

public:
    MaterialZone(int initialCapacity) : capacity(initialCapacity) {}

    std::string getType() const override { return "Material"; }

    void update() override {
        if (capacity > 0 && capacity < 10) {
            ++capacity; // �������������� ����������� ��� � 15-20 ����
            //std::cout << "Material zone capacity increased to " << capacity << "." << std::endl;
        }
    }

    void onAntEnter() override {
        if (capacity > 0) {
            --capacity;
            //std::cout << "An ant collected materials. Remaining capacity: " << capacity << "." << std::endl;
        }
        else {
            //std::cout << "No materials left in this zone." << std::endl;
        }
    }

private:
    int capacity; // ����������� ����������

};

// ���������� ����
class PastureZone : public Zone {


public:
    PastureZone(int initialCapacity) : capacity(initialCapacity) {}

    std::string getType() const override { return "Pasture"; }

    void update() override {
        if (capacity > 0 && capacity < 10) {
            ++capacity; // �������������� ����������� ��� � 15-20 ����
            //std::cout << "Pasture zone capacity increased to " << capacity << "." << std::endl;
        }
    }

    void onAntEnter() override {
        if (capacity > 0) {
            --capacity;
            //std::cout << "An ant grazed in the pasture. Remaining capacity: " << capacity << "." << std::endl;
        }
        else {
            //std::cout << "No grazing available in this zone." << std::endl;
        }
    }

private:
    int capacity; // ����������� �����
};

// ������� ����
class DangerousZone : public Zone {


public:
    DangerousZone(int initialHealth, int maxHealth) : enemyHealth(initialHealth), maxHealth(maxHealth) {}

    std::string getType() const override { return "Dangerous"; }

    void update() override {
        static int daysSinceLastUpdate = 0;
        ++daysSinceLastUpdate;

        if (daysSinceLastUpdate % 5 == 0) {
            enemyHealth -= 10; // ���������� �������� �����
            //std::cout << "Enemy health decreased to " << enemyHealth << "." << std::endl;

            if (enemyHealth <= 0) {
                //std::cout << "Enemy is critically weak. Expanding dangerous zone!" << std::endl;
                // ���������� ������� ����
            }
        }

        if (enemyHealth >= maxHealth) {
            //std::cout << "Enemy reached max health. Expanding dangerous zone!" << std::endl;
            // ���������� ������� ����
        }
    }

    void onAntEnter() override {
        //std::cout << "An ant entered a dangerous zone and died!" << std::endl;
    }

private:
    int enemyHealth;
    int maxHealth;
};

// �������� ����
class GarbageZone : public Zone {


public:
    GarbageZone(int initialGarbage) : garbageAmount(initialGarbage) {}

    std::string getType() const override { return "Garbage"; }

    void update() override {
        // ������ ���������� �������� ����
    }

    void onAntEnter() override {
        //std::cout << "An ant entered a garbage zone." << std::endl;
    }

private:
    int garbageAmount;
};

int main() {
    srand(time(0));

    std::vector<std::shared_ptr<Zone>> zones;
    zones.push_back(std::make_shared<EmptyZone>());
    zones.push_back(std::make_shared<FoodZone>(5));
    zones.push_back(std::make_shared<DangerousZone>(50, 100));

    for (auto& zone : zones) {
        zone->update();
        zone->onAntEnter();
    }

    return 0;
}