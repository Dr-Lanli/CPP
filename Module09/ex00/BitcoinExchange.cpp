#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    _data_csv = other._data_csv;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this->_data_csv != other._data_csv)
    {
        _data_csv = other._data_csv;
    }

    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::print_data()
{
    for (std::map<std::string, int>::iterator it = _data_csv.begin(); it != _data_csv.end(); it++)
    {
        std::cout << "{" << it->first << ", " << it->second << "}" << std::endl;
    }
    
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
        return (false);
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
        return (false);
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
        return (false);
    }

    if (datetime.tm_year != copy.tm_year ||
        datetime.tm_mon  != copy.tm_mon  ||
        datetime.tm_mday != copy.tm_mday)
    {
        std::cout << "Error: Bad input => " << dateStr << std::endl;
        return (false);
    }

    return (true);
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

std::pair<std::string, int> BitcoinExchange::parseLine(std::string &line)
{
    trim(line);
    if (line.find("date|value") != std::string::npos)
        return (std::pair<std::string, int> ());
    size_t midLine = line.find("|");
    if (midLine == std::string::npos)
    {
        std::cout << "Error: Bad input => " << line << std::endl;
        return (std::pair<std::string, int> ());
    }
    std::string dateStr  = line.substr(0, midLine);
    std::string valueStr = line.substr(midLine + 1);

    double doubleValue = parseValue(valueStr);
    parseDate(dateStr);
    
    return (make_pair(dateStr, doubleValue));
}

int BitcoinExchange::extract_csv()
{
    std::ifstream csvFile("data.csv");
    if (!csvFile)
    {
        std::cout << "File doesn't exist" << std::endl;
        return (-1);
    }
    std::string line;

    while (getline (csvFile, line))
    {
        if (line.find("date,exchange_rate") != std::string::npos)
            continue ;
        
        size_t midLine = line.find(",");
        std::string dateStr  = line.substr(0, midLine);
        std::string valueStr = line.substr(midLine + 1);
        char *end;
        double dValue = std::strtod(valueStr.c_str(), &end);
        _data_csv[dateStr] = static_cast<int>(dValue);
        //std::cout << line << std::endl;
    }
    
    return (0);
}

void BitcoinExchange::calculateBtc(std::pair<std::string, int> data_input)
{
    //(void)data_input;
    std::string dateStr = data_input.first;
    int value = data_input.second;

    for (std::map<std::string, int>::iterator it = _data_csv.begin(); it != _data_csv.end(); it++)
    {
        if (dateStr == it->first)
        {
            //std::cout << dateStr << " test " << it->first << std::endl;
            int bitcoinRate = value * it->second;
            std::cout << dateStr << " => " << value << " = " << bitcoinRate << std::endl;
            break ;
        }
        else
        {
            std::map<std::string, int>::iterator lower_date = _data_csv.lower_bound(dateStr);
            if (lower_date == _data_csv.begin()) 
            {
               break ;
            } 
            else 
            {
                if (lower_date == _data_csv.end() || lower_date->first != dateStr)
                    --lower_date;
            }
            int bitcoinRate = lower_date->second * value;
            std::cout << lower_date->second << " test " << value << std::endl;
            std::cout << lower_date->first << " => " << value << " = " << bitcoinRate << std::endl;
            break ;
        }
        
    }
    
}