#include "Span.hpp"

Span::Span()
{
	_N = 0;
}

Span::Span(unsigned int maxElements)
{
	_N = maxElements;
}

Span::~Span()
{
}

Span::Span(const Span &other)
{
    this->_numbers = other._numbers;
	this->_N = other._N;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->_numbers = other._numbers;
		this->_N = other._N;
    }
    return (*this);
}

const char* Span::MaxReachedException::what() const throw() 
{
    return ("Max numbers reached");
}

const char* Span::MoreValuesNeeded::what() const throw() 
{
    return ("Needs at least 2 value to calculate span");
}

void Span::addNumber(int element)
{
	if (_numbers.size() == _N)
		throw MaxReachedException();
	
	_numbers.insert(element);
}

unsigned int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw MoreValuesNeeded();

    unsigned int shortest = UINT_MAX;

    for (std::multiset<int>::iterator it = _numbers.begin(); it != _numbers.end(); ++it)
    {
        std::multiset<int>::iterator next = it;
        next++;

        if (next == _numbers.end())
            break ;

        unsigned int diff = static_cast<unsigned int>(*next - *it);

        if (diff < shortest)
            shortest = diff;
    }

    return (shortest);
	
}

unsigned int Span::longestSpan()
{
	if (_numbers.size() < 2)
        throw MoreValuesNeeded();

	int min = *_numbers.begin();
	int max  = *_numbers.rbegin();

	return (max - min);
}



