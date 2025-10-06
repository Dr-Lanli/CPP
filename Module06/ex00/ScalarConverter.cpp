#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

const char* ScalarConverter::IntConversionException::what() const throw() 
{
    return ("Error while converting to int");
}

const char* ScalarConverter::FloatConversionException::what() const throw() 
{
    return ("Error while converting to float");
}

const char* ScalarConverter::DoubleConversionException::what() const throw() 
{
    return ("Error while converting to double");
}

const char* ScalarConverter::UnknownTypeException::what() const throw() 
{
    return ("Input Error, type undefined");
}



static bool isStrNumbers(const std::string& str)
{
    size_t i = 0;

    if (!str.empty() && (str[0] == '+' || str[0] == '-'))
        i = 1;

    for (; i < str.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return (false);
    }

    return (i > 0);
}

static bool strToFloat(const std::string &str, float &value) 
{
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return (true);
    std::stringstream ss(str);
    ss >> value;
    return (!ss.fail() && ss.eof());
}

static bool strToInt(const std::string &str, int &value) 
{
    std::stringstream ss(str);
    ss >> value;
    return (!ss.fail() && ss.eof());
}

static bool strToDouble(const std::string &str, double &value) 
{
    if (str == "-inf" || str == "+inf" || str == "nan")
        return (true);
    std::stringstream ss(str);
    ss >> value;
    return (!ss.fail() && ss.eof());
}

static int whichTypes(std::string &str)
{
    if (str.size() == 1)
    {
        int n = 0;
        if (!strToInt(str, n))
            throw ScalarConverter::IntConversionException();
        if (isalpha(n))
            return (ScalarConverter::eChar);
    }
    if (str.find('f') != std::string::npos || (str == "-inff" || str == "+inff" || str == "nanf"))
    {
        return (ScalarConverter::eFloat);
    }
    if ((str.find('.') != std::string::npos) || (str == "-inf" || str == "+inf" || str == "nan"))
    {
        return (ScalarConverter::eDouble);
    }
    if (isStrNumbers(str))
    {
        int n = 0;
        if (!strToInt(str, n))
            throw ScalarConverter::IntConversionException();
        
        return (ScalarConverter::eInt);
    }
    std::cout << "test:" << isStrNumbers(str) << std::endl;
    return (ScalarConverter::eUnknown);
}

static void print(std::string &str, char c, int i, float f, double d, bool flag)
{
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    if (flag)
    {
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str << std::endl;
        return ;
    }
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
    
}

static void print(char c, int i, float f, double d)
{
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
    
}

static void fromCharTo(char c)
{
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    print(c, i, f, d);
}

static void fromDoubleTo(std::string &str, float f, bool flag)
{
    int i = static_cast<int>(f);
    char c = static_cast<char>(f);
    if (!flag)
        double d = static_cast<double>(f);
    double d = 0;
    print(str, c, i, f, d, flag);
}

static void fromFloatTo(std::string &str, float f, bool flag)
{
    int i = static_cast<int>(f);
    char c = static_cast<char>(f);
    if (!flag)
        float d = static_cast<float>(f);
    float d = 0;
    print(str, c, i, f, d, flag);
}

static void fromIntTo(int i)
{
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    print(c, i, f, d);
}

void ScalarConverter::convert(std::string &str)
{
    if (str.empty())
        return ;
    
    int type = whichTypes(str);
    switch (type)
    {
        case ScalarConverter::eChar:
        {        
            const char *cStr = str.c_str();
            char c = *cStr;
            fromCharTo(c);
            break;
        }
        case ScalarConverter::eFloat:
        {
            float f = 0;
            if (!strToFloat(str, f))
                throw ScalarConverter::FloatConversionException();
            if (str == "-inff" || str == "+inff" || str == "nanf")
            {
                fromFloatTo(str, f, true);
                break;
            }
            fromFloatTo(str, f, false);
            break;
        }
        case ScalarConverter::eDouble:
        {
            double d = 0;
            if (!strToDouble(str, d))
                throw ScalarConverter::DoubleConversionException();
            if (str == "-inf" || str == "+inf" || str == "nan")
            {
                fromDoubleTo(str, d, true);
                break;
            }
            fromDoubleTo(str, d, false);
            break;
        }
        case ScalarConverter::eInt:
        {
            int n = 0;
            if (!strToInt(str, n))
                throw ScalarConverter::IntConversionException();
            fromIntTo(n);
            break;
        }
        default:
            throw ScalarConverter::UnknownTypeException();
            break;
    }
}