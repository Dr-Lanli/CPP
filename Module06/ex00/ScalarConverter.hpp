#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <limits.h>

class ScalarConverter
{
private:
public:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);

    static void convert(std::string &str);

    enum eTypes{
        eChar,
        eInt,
        eDouble,
        eFloat,
        eUnknown
    };

    class IntConversionException : public std::exception 
    {
        public:
        const char* what() const throw();
    };

    class FloatConversionException : public std::exception 
    {
        public:
        const char* what() const throw();
    };

    class DoubleConversionException : public std::exception 
    {
        public:
        const char* what() const throw();
    };

    class UnknownTypeException : public std::exception 
    {
        public:
        const char* what() const throw();
    };
};




#endif