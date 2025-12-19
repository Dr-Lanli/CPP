#include "Span.hpp"
#include <vector>

int main (void)
{
	{
		std::cout << "Test Positive numbers: " << std::endl;

		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;
	}
	{
		std::cout << "Test Negative numbers: " << std::endl;
	
		Span sp = Span(5);

		sp.addNumber(-6);
		sp.addNumber(-3);
		sp.addNumber(-17);
		sp.addNumber(-9);
		sp.addNumber(-11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;
	}
	{
		std::cout << "Test Mixed numbers: " << std::endl;
	
		Span sp = Span(5);

		sp.addNumber(-6);
		sp.addNumber(-3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;
	}
	{
		std::cout << "Test Same numbers: " << std::endl;
	
		Span sp = Span(5);

		sp.addNumber(-6);
		sp.addNumber(-6);
		sp.addNumber(-6);
		sp.addNumber(-6);
		sp.addNumber(-6);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;
	}
	{
		std::cout << "Test exception: overflow" << std::endl;
		Span sp(3);
		try {
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4); // Doit lever une exception
		} catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "Test exception: not enough values" << std::endl;
		Span sp(2);
		sp.addNumber(42);
		try {
			sp.shortestSpan();
		} catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		try {
			sp.longestSpan();
		} catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "Test a lot of values (10 000 numbers)" << std::endl;
		Span sp(10000);
		std::vector<int> v;
		for (int i = 0; i < 10000; ++i)
			v.push_back(i * 2); // Espacement régulier
		sp.addNumbers(v.begin(), v.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Using addNumbers() (std::vector)" << std::endl;
		Span sp(6);
		std::vector<int> v;
		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		v.push_back(40);
		v.push_back(50);
		v.push_back(60);
		sp.addNumbers(v.begin(), v.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}

    return (0);
}