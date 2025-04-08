#pragma once

#include <cmath>

class Vec2 {
public:
    Vec2(float x = 0, float y = 0) : x(x), y(y) {}

    float getX() const { return x; }
    float getY() const { return y; }

    void set(float newX, float newY);

    Vec2 add(const Vec2& other) const;

    Vec2 scale(float scalar) const;

private:
    float x;
    float y;
};