#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Zone.h"

using namespace std;

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