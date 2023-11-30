#pragma once
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float a, const float b);
		Point(const Fixed a, const Fixed b);
		Point(const Point& source);
		Point&			operator=(const Point& source);
		Point			operator-(const Point& source) const;
		~Point(void);
		Fixed			GetX(void) const;
		Fixed			GetY(void) const;
		static Fixed	CrossProduct(const Point vecA, const Point vecB);
	private:
		Fixed const	x;
		Fixed const	y;
};
#endif
