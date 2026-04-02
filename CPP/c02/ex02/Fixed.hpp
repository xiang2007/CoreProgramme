#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <bits/stdc++.h>

using std::cout;
using std::endl;

class	Fixed{
	private:
		int					value;
		static const int	int_literal = 8;

	public:
		Fixed(void);
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& ot);
		Fixed &operator=(const Fixed& ot);
		bool operator>(const Fixed& ot) const;
		bool operator<(const Fixed& ot) const;
		bool operator>=(const Fixed& ot) const ;
		bool operator<=(const Fixed& ot) const ;
		bool operator==(const Fixed& ot) const ;
		bool operator!=(const Fixed& ot) const ;
		~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed &ot);

#endif