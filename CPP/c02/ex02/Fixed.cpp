#include "Fixed.hpp"

Fixed::Fixed(void) {
	cout << "Default constructor called" << endl;
	value = 0;
}

Fixed::Fixed(const Fixed& ot) {
	cout << "Copy constructor called" << endl;
	value =  ot.value;
}

Fixed::Fixed(const int i)
{
	cout << "Int constructor called" << endl;
	value = i;
}

Fixed::Fixed(const float f)
{
	cout << "Float constructor called" << endl;
	value = f;
}

Fixed &Fixed::operator=(const Fixed &ot) {
	cout << "Copy asignment operator called" << endl;
	if (this != &ot)
		value = ot.value;
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Fixed& ot) {
	return os << ot.toFloat();
}

bool Fixed::operator>(const Fixed& ot) const
{
	return ((value) > ot.toFloat());
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

float Fixed::toFloat(void) const
{
	return ((float)value);
}

int Fixed::toInt(void) const
{
	return ((int)value);
}