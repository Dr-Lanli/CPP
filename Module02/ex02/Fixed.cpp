#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	_value = i << _fract_bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(f * (1 << _fract_bits));
}

Fixed::~Fixed()
{
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->_value + other._value);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->_value - other._value);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->_value * other._value);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->_value / other._value);
}

int Fixed::toInt(void) const
{
	return (_value >> _fract_bits);
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _fract_bits));
}

Fixed Fixed::min(Fixed &a, Fixed &b)
{
	if (a._value < b._value)
		return (a);
	return (b);
}

Fixed Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._value < b._value)
		return (a);
	return (b);
}

Fixed Fixed::max(Fixed &a, Fixed &b)
{
	if (a._value > b._value)
		return (a);
	return (b);	
}

Fixed Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._value > b._value)
		return (a);
	return (b);
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
    return (os);
}

Fixed::Fixed(const Fixed &other)
{
    this->_value = other._value;
}


