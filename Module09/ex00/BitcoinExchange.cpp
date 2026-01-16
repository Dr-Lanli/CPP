#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    _data = other._data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this->_data != other._data)
    {
        _data = other._data;
    }

    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

static bool isSpace(char c)
{
    return (c == ' ' || c == '\t');
}

void BitcoinExchange::trim(std::string &line)
{
    line.erase(
        std::remove_if(line.begin(), line.end(), isSpace),
        line.end()
    );
}

bool BitcoinExchange::longConverter(std::string &str, long &value)
{
    char *end;
    errno = 0;
    value = std::strtol(str.c_str(), &end, 10);

    if (errno != 0 || *end != '\0')
    {
        //std::cout << "Error: Bad input => " << str << std::endl;
        return (false);
    }

    return (true);
}

bool BitcoinExchange::parseDate(std::string &dateStr)
{
    if (dateStr.size() != 10 ||
        (dateStr[4] != '-' || dateStr[7] != '-'))
    {
        std::cout << "Error: Bad input => " << dateStr << std::endl;
        return ;
    }
    
    std::string year  = dateStr.substr(0, 4);
    std::string month  = dateStr.substr(5, 2);
    std::string day  = dateStr.substr(8, 2);

    long yearLong = 0;
    long monthLong = 0;
    long dayLong = 0;


    if (!longConverter(year, yearLong) || 
        !longConverter(month, monthLong) || 
        !longConverter(day, dayLong))
    {
        std::cout << "Error: Bad input => " << dateStr << std::endl;
        return ;
    }

    struct tm datetime;

    //std::cout << yearLong << " " << monthLong << " " << dayLong << std::endl;
    datetime.tm_year = static_cast<int>(yearLong) - 1900; // Number of years since 1900
    datetime.tm_mon = static_cast<int>(monthLong) - 1; // Number of months since January
    datetime.tm_mday = static_cast<int>(dayLong);
    datetime.tm_hour = 0;
    datetime.tm_min = 0;
    datetime.tm_sec = 0;
    datetime.tm_isdst = -1;

    tm copy = datetime;

    if (mktime(&datetime) == -1)
    {
        std::cout << "Error: Bad input => " << dateStr << std::endl;
        return ;
    }

    if (datetime.tm_year != copy.tm_year ||
        datetime.tm_mon  != copy.tm_mon  ||
        datetime.tm_mday != copy.tm_mday)
    {
        std::cout << "Error: Bad input => " << dateStr << std::endl;
        return ;
    }
}

bool BitcoinExchange::doubleConverter(std::string &str, double &value)
{
    char *end;
    errno = 0;
    value = std::strtod(str.c_str(), &end);

    if (errno != 0 || *end != '\0')
    {
        //std::cout << "Error: Bad input => " << str << std::endl;
        return (false);
    }

    return (true);
}

double BitcoinExchange::parseValue(std::string &valueStr)
{
    double dValue = 0;

    if (!doubleConverter(valueStr, dValue) || (dValue < 0.0 || dValue > 1000.0))
    {
        std::cout << "Error: Bad input => " << valueStr << std::endl;
        return (-1);
    }
    return (dValue);
}

void BitcoinExchange::parseLine(std::string &line)
{
    trim(line);
    if (line.find("date|value") != std::string::npos)
        return ;
    size_t midLine = line.find("|");
    if (midLine == std::string::npos)
    {
        std::cout << "Error: Bad input => " << line << std::endl;
        return ;
    }
    std::string dateStr  = line.substr(0, midLine);
    std::string valueStr = line.substr(midLine + 1);

    double doubleValue = parseValue(valueStr);
    if (parseDate(dateStr) && doubleValue)
    {
        _data[dateStr] = doubleValue;
    }
    

}