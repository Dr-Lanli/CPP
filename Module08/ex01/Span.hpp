#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
private:

public:
    Span();
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

};

#endif