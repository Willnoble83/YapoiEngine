#pragma once

namespace YapoiEngine
{
	 struct vector2D {
		vector2D(void) { _x = 0; _y = 0; };
		vector2D(float x, float y) { _x = x; _y = y; };
		float _x;
		float _y;

		vector2D operator+(const vector2D& other)
		{
			return vector2D(_x + other._x, _y + other._y);
		}

		vector2D operator-(const vector2D& other)
		{
			return vector2D(_x - other._x, _y - other._y);
		}
		vector2D operator*(const vector2D& other)
		{
			return vector2D(_x * other._x, _y * other._y);
		}
		vector2D operator/(const vector2D& other)
		{
			return vector2D(_x / other._x, _y / other._y);
		}
		bool operator==(const vector2D& other)
		{
			return (_x == other._x && _y == other._y);
		}
		vector2D operator=(const vector2D& other)
		{
			this->_x = other._x;
			this->_y = other._y;
			return *this;
		}
		vector2D operator+=(const vector2D& other)
		{
			this->_x = this->_x + other._x;
			this->_y = this->_y + other._y;
			return *this;
		}
	};
}