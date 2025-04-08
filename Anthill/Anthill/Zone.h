#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
using namespace std;

// ������� ����� ��� ���� ���
class Zone 
{
public:
    virtual ~Zone() = default;

    // ���������� ��������� ���� (For instance: �������������� �������� ��� ����������)
    virtual void update() = 0;

    // �������. ���� ����
    virtual string getType() const = 0;

    // �������� �������� ����
    virtual bool isEmpty() const { return false; }

    // ��� �����, ���� ������� ����� � ����
    virtual void onAntEnter() = 0;
};