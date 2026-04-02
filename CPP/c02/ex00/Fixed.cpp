#include "Fixed.hpp"

Fixed::Fixed(void) {
	cout << "Default constructor called" << endl;
	value = 0;
}

Fixed::Fixed(const Fixed& ot) {
	cout << "Copy constructor called" << endl;
	value =  ot.value;
}

Fixed &Fixed::operator=(const Fixed &ot) {
	cout << "Copy asignment operator called" << endl;
	if (this != &ot)
		value = ot.value;
	return *this;
}

Fixed::~Fixed(void)
{
	cout << "Destructor called" << endl;
}

int	Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	cout << "setRawBits member function called" << endl;
	value = raw;
}