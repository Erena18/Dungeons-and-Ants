#pragma once
#include "Vec2.h"
#include <cstdlib>

class AntLogic {
public:
    AntLogic(Vec2 startPos, float speed = 100.0f)
        : position(startPos), speed(speed), velocity(getRandomDirection()) {}

    void update(float dt, int width, int height);

    Vec2 getPosition() const { return position; }

private:
    Vec2 position;      //���. �������
    Vec2 velocity;      //����������� ��������
    float speed;        //�������� �������

    //����� ���������� ��������� ����������� ��� ��������
    Vec2 getRandomDirection();
};