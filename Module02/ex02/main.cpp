#include "Fixed.hpp"

int main (void)
{
	Fixed a;
	Fixed const g( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << g << std::endl;
	
	std::cout << Fixed::max( a, g ) << std::endl;

    Fixed b(10);
    Fixed c(99.99f);
    Fixed d(b);
    Fixed e;                  
    e = c;

	std::cout << std::endl;
	std::cout << "=== More Testing: ===" << std::endl << std::endl;
    std::cout << "Values:" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;

    std::cout << "\nComparisons:" << std::endl;
    std::cout << "b > c ? " << (b > c) << std::endl;
    std::cout << "b < c ? " << (b < c) << std::endl;
    std::cout << "b == d ? " << (b == d) << std::endl;

    std::cout << "\nArithmetic:" << std::endl;
    std::cout << "b + c = " << (b + c) << std::endl;
    std::cout << "c - b = " << (c - b) << std::endl;
    std::cout << "b * c = " << (b * c) << std::endl;
    std::cout << "c / b = " << (c / b) << std::endl;

    std::cout << "\nIncrement / Decrement:" << std::endl;
    Fixed f;
    std::cout << "f = " << f << std::endl;
    std::cout << "++f = " << ++f << std::endl;
    std::cout << "f++ = " << f++ << " (after: " << f << ")" << std::endl;
    std::cout << "--f = " << --f << std::endl;
    std::cout << "f-- = " << f-- << " (after: " << f << ")" << std::endl;

    std::cout << "\nMin / Max:" << std::endl;
    std::cout << "min(b, c) = " << Fixed::min(b, c) << std::endl;
    std::cout << "max(b, c) = " << Fixed::max(b, c) << std::endl;
	std::cout << std::endl << "=============" << std::endl;

	return (0);
}