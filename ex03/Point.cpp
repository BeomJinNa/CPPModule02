#include "Point.hpp"

Point::Point(void)
	: x(0)
	, y(0)
{
}

Point::Point(const float a, const float b)
	: x(Fixed(a))
	, y(Fixed(b))
{
}

Point::Point(const Fixed a, const Fixed b)
	: x(a)
	, y(b)
{
}

Point::Point(const Point&	source)
	: x(source.x)
	, y(source.y)
{
}

Point&	Point::operator=(const Point& source)
{
	if (this != &source)
	{
		const_cast<Fixed&>(x) = source.x;
		const_cast<Fixed&>(y) = source.y;
	}
	return (*this);
}

Point	Point::operator-(const Point& source) const
{
	return (Point(x - source.x, y - source.y));
}

Point::~Point(void)
{
}

Fixed	Point::GetX(void) const { return (x); }
Fixed	Point::GetY(void) const { return (y); }

Fixed	Point::CrossProduct(const Point vecA, const Point vecB)
{
	return ((vecA.GetX() * vecB.GetY())
			- (vecB.GetX() * vecA.GetY()));
}
