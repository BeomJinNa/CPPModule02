#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& source);
		Fixed&	operator=(const Fixed& source);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const value);
	private:
		int					mValue;
		static const int	mFractional;
};
#endif
