#include <iostream>
#include "Fixed.hpp"

const int	Fixed::mFractional = 8;

Fixed::Fixed(void)
	:mValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& source)
{
	std::cout << "Copy constructor called" << std::endl;
	mValue = source.getRawBits();
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

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (mValue);
}

void	Fixed::setRawBits(int const value) { mValue = value; }
