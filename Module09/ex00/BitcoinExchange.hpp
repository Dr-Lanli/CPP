#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cerrno>

class BitcoinExchange
{
    private:
        std::map<std::string, int> _data;
        static void trim(std::string &line);
        static bool parseDate(std::string &dateStr);
        static double parseValue(std::string &valueStr);
        static bool longConverter(std::string &str, long &value);
        static bool doubleConverter(std::string &str, double &value);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void parseLine(std::string &line);

};

#endif