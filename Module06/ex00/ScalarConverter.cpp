#include "ScalarConverter.hpp"
#include <cctype>

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
    if (str.empty())
        return (false);
    size_t i = 0;
    if (str[0] == '+' || str[0] == '-')
        i = 1;
    bool hasDigit = false;
    for (; i < str.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return (false);
        hasDigit = true;
    }
    return (hasDigit);
}

static void printChar(char c)
{
    if (std::isprint(static_cast<unsigned char>(c)))
    {
        std::cout << "char: " << "'" << c << "'" << std::endl;
    }
    else
    {
        std::cout << "char: Non displayable" << std::endl;
    }
}

static bool strToFloat(const std::string &str, float &value) 
{
    if (str == "-inff" || str == "+inff")
    {
        value = (str[0] == '-') ? -std::numeric_limits<float>::infinity() : std::numeric_limits<float>::infinity();
        return (true);
    }
    if (str == "nanf")
    {
        value = std::numeric_limits<float>::quiet_NaN();
        return (true);
    }
    std::string tmp = str;
    if (!tmp.empty() && tmp[tmp.size() - 1] == 'f')
        tmp.erase(tmp.size() - 1);
    std::stringstream ss(tmp);
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
    if (str == "-inf" || str == "+inf")
    {
        value = (str[0] == '-') ? -std::numeric_limits<double>::infinity() : std::numeric_limits<double>::infinity();
        return (true);
    }
    if (str == "nan")
    {
        value = std::numeric_limits<double>::quiet_NaN();
        return (true);
    }
    std::stringstream ss(str);
    ss >> value;
    return (!ss.fail() && ss.eof());
}

static int whichTypes(const std::string &str)
{
    if (str.size() == 1)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[0])))
            return (ScalarConverter::eChar);
        // single digit -> traité comme un int
    }
    if (str == "-inf" || str == "+inf" || str == "nan")
        return (ScalarConverter::eDouble);
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return (ScalarConverter::eFloat);

    // float suffix: contient un '.' et un 'f' a la fin
    if (str.size() >= 2 && str[str.size() - 1] == 'f')
    {
        std::string tmp = str.substr(0, str.size() - 1);
        if (tmp.find('.') != std::string::npos)
            return (ScalarConverter::eFloat);
    }

    // double: contient un '.' et pas de f a la fin
    if (str.find('.') != std::string::npos)
        return (ScalarConverter::eDouble);

    if (isStrNumbers(str))
    {
        int n = 0;
        if (!strToInt(str, n))
            throw ScalarConverter::IntConversionException();
        return (ScalarConverter::eInt);
    }
    return (ScalarConverter::eUnknown);
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

static void fromDoubleOrFloatTo(const std::string &str, double value, const std::string &type)
{
    if (std::isnan(value) || std::isinf(value))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (type == "double")
        {
            std::cout << "float: " << str << "f" << std::endl;
            std::cout << "double: " << str << std::endl;
        }
        else if (type == "float")
        {
            std::cout << "float: " << str << std::endl;
            std::string d = str;
            if (!d.empty() && d[d.size() - 1] == 'f')
                d.erase(d.size() - 1);
            std::cout << "double: " << d << std::endl;
        }
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

    if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
    {
        float f = static_cast<float>(value);
        // set affichage en fixe et a un niveau de précision de 1 après le '.'
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

void ScalarConverter::convert(const std::string &str)
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
            break ;
        }
        case ScalarConverter::eFloat:
        {
            float f = 0;
            if (!strToFloat(str, f))
                throw ScalarConverter::FloatConversionException();
            if (str == "-inff" || str == "+inff" || str == "nanf")
            {
                fromDoubleOrFloatTo(str, static_cast<double>(f), "float");
                break ;
            }
            fromDoubleOrFloatTo(str, static_cast<double>(f), "");
            break ;
        }
        case ScalarConverter::eDouble:
        {
            double d = 0;
            if (!strToDouble(str, d))
                throw ScalarConverter::DoubleConversionException();
            if (str == "-inf" || str == "+inf" || str == "nan")
            {
                fromDoubleOrFloatTo(str, d, "double");
                break ;
            }
            fromDoubleOrFloatTo(str, d, "");
            break ;
        }
        case ScalarConverter::eInt:
        {
            int n = 0;
            if (!strToInt(str, n))
                throw ScalarConverter::IntConversionException();
            fromIntTo(n);
            break ;
        }
        default:
            throw ScalarConverter::UnknownTypeException();
            break ;
    }
}