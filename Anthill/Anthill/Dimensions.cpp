#include "Dimensions.h"

void Vec2::set(float newX, float newY)
{
	x = newX;
	y = newY;
}

Vec2 Vec2::add(const Vec2& other) const
{
	return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::scale(float scalar) const
{
	return Vec2(x * scalar, y * scalar);
}