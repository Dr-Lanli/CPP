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

static void printChar(char c)
{
    if (c > 31 && c < 127)
    {
        std::cout << "char: " << "'" << c << "'" << std::endl;
    }
    else if (c < 32)
    {
        std::cout << "char: non printable character" << std::endl;
    }
    else
    {
        std::cout << "char: non displayable character" << std::endl;
    }
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
        if (isalpha(str[0]))
            return (ScalarConverter::eChar);
    }
    else if (str == "-inf" || str == "+inf" || str == "nan")
    {
        return (ScalarConverter::eDouble);
    }
    else if (str == "-inff" || str == "+inff" || str == "nanf")
    {
        return (ScalarConverter::eFloat);
    }
    else if ((str.find('.') != std::string::npos) && !(str.find('f') != std::string::npos))
    {
        return (ScalarConverter::eDouble);
    }
    else if ((str.find('f') != std::string::npos) && (str.find('.') != std::string::npos))
    {
        str.erase(str.size() - 1);
        return (ScalarConverter::eFloat);
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

static void print(std::string &str, char c, int i, float f, double d, std::string &type)
{
    if (type == "double")
    {
        std::cout << "int: impossible" << std::endl;
        std::cout << "char: impossible" << std::endl;
        std::cout << "float: " << str + "f" << std::endl;
        std::cout << "double: " << str << std::endl;
        return ;
    }
    else if (type == "float")
    {
        std::cout << "int: impossible" << std::endl;
        std::cout << "char: impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
        str.erase(str.size() - 1);
        std::cout << "double: " << str << std::endl;
        return ;
    }
    printChar(c);
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
    
}

static void print(char c, int i, float f, double d)
{
    printChar(c);
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

static void fromCharTo(char c)
{
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    print(c, i, f, d);
}

static void fromDoubleOrFloatTo(std::string &str, double value, std::string type)
{
    if (std::isnan(value) || std::isinf(value))
    {
        print(str, 0, 0, static_cast<float>(value), value, type);
        return ;
    }

    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else
        printChar(static_cast<char>(value));

    float f;
    if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
    {
        f = static_cast<float>(value);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
    }

    std::cout << "double: " << value << std::endl;
}

static void fromIntTo(int i)
{
    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else
        printChar(static_cast<char>(i));
    std::cout << "int: " << i << std::endl;

    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
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
                fromDoubleOrFloatTo(str, static_cast<double>(f), "float");
                break;
            }
            fromDoubleOrFloatTo(str, static_cast<double>(f), "");
            break;
        }
        case ScalarConverter::eDouble:
        {
            double d = 0;
            if (!strToDouble(str, d))
                throw ScalarConverter::DoubleConversionException();
            if (str == "-inf" || str == "+inf" || str == "nan")
            {
                fromDoubleOrFloatTo(str, d, "double");
                break;
            }
            fromDoubleOrFloatTo(str, d, "");
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