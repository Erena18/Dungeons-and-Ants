#pragma once

#include <cmath>

class Vec2 {
private:
    float x;
    float y;

public:
    Vec2(float x = 0, float y = 0) : x(x), y(y) {}

    float getX() const { return x; }
    float getY() const { return y; }

    void set(float newX, float newY) { x = newX; y = newY; }

    Vec2 add(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 scale(float scalar) const {
        return Vec2(x * scalar, y * scalar);
    }
};