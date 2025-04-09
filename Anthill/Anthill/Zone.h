#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
using namespace std;

class Zone 
{
public:
    virtual ~Zone() = default;

    // ���������� ��������� ����
    virtual void update() = 0;
    virtual string getType() const = 0;
    virtual bool isEmpty() const { return false; }
    virtual void onAntEnter() = 0;
};

class ZoneManager 
{
public:
    static ZoneManager& getInstance()
    {
        static ZoneManager instance;
        return instance;
    }
    Zone* getCurrentZone(Ant& ant) 
    {
       // ������ ����������� ������� ���� (����) �� ������ ��������� �������
        return currentZone;
    }

private:
    Zone* currentZone;
};