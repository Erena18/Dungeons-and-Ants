#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Zone.h"

using namespace std;

class EmptyZone : public Zone 
{

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
