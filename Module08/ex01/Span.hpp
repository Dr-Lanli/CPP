#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <climits>
#include <set>

class Span
{
private:
	std::multiset<int> _numbers;
	unsigned int _N;
public:
    Span();
	Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

	void addNumber(int element);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	class MaxReachedException : public std::exception 
    {
        public:
        const char* what() const throw();
    };
		
	class MoreValuesNeeded : public std::exception 
    {
        public:
        const char* what() const throw();
    };

	template <typename T>
	void addNumbers(T first, T last)
	{
		size_t distance = std::distance(first, last);
		if (_numbers.size() + distance > _N)
			throw MaxReachedException();
		for (; first != last; ++first)
			addNumber(*first);
	}
    
};

#endif