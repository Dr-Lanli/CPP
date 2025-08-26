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
	int toInt(void) const;
	float toFloat(void) const;
	bool operator<(const Fixed &other) const;
	bool operator>(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	static Fixed min(Fixed &a, Fixed &b);
	static Fixed min(const Fixed &a, const Fixed &b);
	static Fixed max(Fixed &a, Fixed &b);
	static Fixed max(const Fixed &a, const Fixed &b);
	~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);


#endif