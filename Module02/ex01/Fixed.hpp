#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

class Fixed
{
private:
	int _value;
	static const int _fract_bits = 8;
public:
	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int toInt(void) const;
	float toFloat(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif