#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int number);
		Fixed(const float fnumber);
		Fixed(const Fixed& source);
		Fixed&				operator=(const Fixed& source);
		~Fixed(void);
		int					getRawBits(void) const;
		void				setRawBits(int const value);
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed&		min(Fixed& former, Fixed& latter);
		static Fixed&		max(Fixed& former, Fixed& latter);
		static const Fixed&	min(const Fixed& former, const Fixed& latter);
		static const Fixed&	max(const Fixed& former, const Fixed& latter);
		bool				operator>(const Fixed& source) const;
		bool				operator>=(const Fixed& source) const;
		bool				operator<(const Fixed& source) const;
		bool				operator<=(const Fixed& source) const;
		bool				operator==(const Fixed& source) const;
		bool				operator!=(const Fixed& source) const;
		Fixed				operator+(const Fixed& source) const;
		Fixed				operator-(const Fixed& source) const;
		Fixed				operator*(const Fixed& source) const;
		Fixed				operator/(const Fixed& source) const;
		Fixed&				operator++(void);
		Fixed&				operator--(void);
		Fixed				operator++(int);
		Fixed				operator--(int);
	private:
		int					mValue;
		static const int	mFractional;
		static const int	mPowi;
		static const float	mPow;
};

std::ostream&	operator<<(std::ostream& out, const Fixed &self);
#endif
