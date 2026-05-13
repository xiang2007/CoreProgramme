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
	value = roundf(f * (1 << int_literal));
}


Fixed &Fixed::operator=(const Fixed &ot) {
	cout << "Copy assignment operator called" << endl;
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

bool Fixed::operator<(const Fixed& ot) const
{
	return ((value) < ot.toFloat());
}

bool Fixed::operator>=(const Fixed& ot) const
{
	return ((value) >= ot.toFloat());
}

bool Fixed::operator<=(const Fixed& ot) const
{
	return ((value) <= ot.toFloat());
}

bool Fixed::operator==(const Fixed& ot) const
{
	return ((value) == ot.toFloat());
}

bool Fixed::operator!=(const Fixed& ot) const
{
	return ((value) != ot.toFloat());
}

Fixed Fixed::operator+(const Fixed& l) const
{
	Fixed res(value + l.toFloat());
	return (res);
}

Fixed Fixed::operator-(const Fixed& l) const
{
	Fixed res(value - l.toFloat());
	return (res);
}

Fixed Fixed::operator*(const Fixed& l) const
{
	Fixed res(value * l.toFloat());
	return (res);
}

Fixed Fixed::operator/(const Fixed& l) const
{
	Fixed res(value / l.toFloat());
	return (res);
}

Fixed &Fixed::operator++()
{
	value++;
	return *this;
}

Fixed &Fixed::operator--()
{
	value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed r;
	r.value++;
	return r;
}

Fixed Fixed::operator--(int)
{
	Fixed r;
	r.value--;
	return r;
}

Fixed::~Fixed(void)
{
	cout << "Destructor called" << endl;
}

Fixed &Fixed::min(Fixed& n1, Fixed& n2)
{
	if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}

const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2)
{
	if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed &Fixed::max(Fixed& n1, Fixed& n2)
{
	if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	return (n2);
}

const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2)
{
	if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	return (n2);
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
	return ((float)(value / (float)(1 << int_literal)));
}

int Fixed::toInt(void) const
{
	return ((int)(value / (float)(1 << int_literal)));
}
