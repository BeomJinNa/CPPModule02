#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::mFractional = 8;
const int	Fixed::mPowi = 1 << Fixed::mFractional;
const float	Fixed::mPow = static_cast<float>(mPowi);

Fixed::Fixed(void)
	:mValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
	:mValue(number * mPowi)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
	:mValue(roundf(number * mPow))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Fixed&	Fixed::operator=(const Fixed& source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
		mValue = source.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const { return (mValue); }
void	Fixed::setRawBits(int const value) { mValue = value; }
float	Fixed::toFloat(void) const { return (static_cast<float>(mValue) / mPow); }
int		Fixed::toInt(void) const { return (mValue / mPow); }

std::ostream&	operator<<(std::ostream& out, const Fixed &source)
{
	out << source.toFloat();
	return (out);
}
