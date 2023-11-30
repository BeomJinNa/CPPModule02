#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point	vecPA = a - point;
	Point	vecPB = b - point;
	Point	vecPC = c - point;
	Fixed	directionAB = Point::CrossProduct(vecPA, vecPB);
	Fixed	directionBC = Point::CrossProduct(vecPB, vecPC);
	Fixed	directionCA = Point::CrossProduct(vecPC, vecPA);

	if (directionAB == 0 || directionBC == 0 || directionCA == 0
	|| (directionAB > 0 && directionBC > 0 && directionCA > 0)
	|| (directionAB < 0 && directionBC < 0 && directionCA < 0))
	{
		return (true);
	}
	return (false);
}
