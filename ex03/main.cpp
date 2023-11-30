#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

namespace
{
	void	checkPoint(Point const a, Point const b,
			Point const c, Point const point);
}

int	main(void)
{
	Point	A(0,0);
	Point	B(5,0);
	Point	C(0,5);
	Point	P(1,1);

	checkPoint(A, B, C, P); //IN
	P = Point(5,5);
	checkPoint(A, B, C, P); //OUT
	P = Point(-1, -1);
	checkPoint(A, B, C, P); //OUT
	P = Point(0, 0);
	checkPoint(A, B, C, P); //IN

	B = Point(2, 3);
	C = Point(-1, 5);
	P = Point(0, 1);
	checkPoint(A, B, C, P); //IN
	P = Point(0, -4);
	checkPoint(A, B, C, P); //OUT
	B = Point(2.05f, 3.12f);
	C = Point(-1.2f, 4.9f);
	P = Point(0, -1.23f);
	checkPoint(A, B, C, P); //OUT
	return (0);
}

namespace
{
	void	checkPoint(Point const a, Point const b,
			Point const c, Point const point)
	{
		if (bsp(a, b, c, point))
		std::cout << "Check Point(" << point.GetX() << ", "
			<< point.GetY() << ") :IN" << std::endl;
		else
		std::cout << "Check Point(" << point.GetX() << ", "
			<< point.GetY() << ") :OUT" << std::endl;
	}
}
