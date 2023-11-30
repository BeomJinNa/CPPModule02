#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::mFractional = 8;
const int	Fixed::mPowi = 1 << Fixed::mFractional;
const float	Fixed::mPow = static_cast<float>(Fixed::mPowi);

Fixed::Fixed(void) :mValue(0)
{
}

Fixed::Fixed(const int number)
	:mValue(number * mPowi)
{
}

Fixed::Fixed(const float number)
	:mValue(roundf(number * mPow))
{
}

Fixed::Fixed(const Fixed& source)
	:mValue(source.getRawBits())
{
}

Fixed&	Fixed::operator=(const Fixed& source)
{
	if (this != &source)
		mValue = source.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
}

int		Fixed::getRawBits(void) const { return (mValue); }
void	Fixed::setRawBits(int const value) { mValue = value; }
float	Fixed::toFloat(void) const { return (static_cast<float>(mValue) / mPow); }
int		Fixed::toInt(void) const { return (mValue / mPow); }

bool	Fixed::operator>(const Fixed& source) const
{
	return (this->getRawBits() > source.getRawBits());
}
bool	Fixed::operator<(const Fixed& source) const
{
	return (this->getRawBits() < source.getRawBits());
}

bool	Fixed::operator>=(const Fixed& source) const
{
	return (this->getRawBits() >= source.getRawBits());
}

bool	Fixed::operator<=(const Fixed& source) const
{
	return (this->getRawBits() <= source.getRawBits());
}

bool	Fixed::operator!=(const Fixed& source) const
{
	return (this->getRawBits() != source.getRawBits());
}

bool	Fixed::operator==(const Fixed& source) const
{
	return (this->getRawBits() == source.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& source) const
{
	Fixed	output(this->toFloat() + source.toFloat());

	return (output);
}

Fixed	Fixed::operator-(const Fixed& source) const
{
	Fixed	output(this->toFloat() - source.toFloat());

	return (output);
}

Fixed	Fixed::operator*(const Fixed& source) const
{
	Fixed	output(this->toFloat() * source.toFloat());

	return (output);
}

Fixed	Fixed::operator/(const Fixed& source) const
{
	Fixed	output(this->toFloat() / source.toFloat());

	return (output);
}

Fixed&	Fixed::operator++(void)
{
	this->mValue += 1;

	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->mValue -= 1;

	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	this->mValue += 1;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	this->mValue -= 1;
	return (temp);
}

std::ostream&	operator<<(std::ostream& out, const Fixed &source)
{
	out << source.toFloat();
	return (out);
}

Fixed&	Fixed::min(Fixed& former, Fixed& latter)
{
	if (former > latter)
		return (latter);
	return (former);
}

Fixed&	Fixed::max(Fixed& former, Fixed& latter)
{
	if (former > latter)
		return (former);
	return (latter);
}

const Fixed&	Fixed::min(const Fixed& former, const Fixed& latter)
{
	if (former > latter)
		return (latter);
	return (former);
}

const Fixed&	Fixed::max(const Fixed& former, const Fixed& latter)
{
	if (former > latter)
		return (former);
	return (latter);
}
