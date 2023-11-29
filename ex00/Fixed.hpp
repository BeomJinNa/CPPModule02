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
		const static int	mFractional = 8;
};
