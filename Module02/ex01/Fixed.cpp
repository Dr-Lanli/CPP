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
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) 
	{
		this->_value = other._value;
	}
	return (*this);
}

int Fixed::toInt(void) const
{
	return (_value >> _fract_bits);
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _fract_bits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
    return (os);
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
    this->_value = other._value;
}
