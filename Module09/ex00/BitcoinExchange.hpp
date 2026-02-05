#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cerrno>
#include <utility>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _data_csv;
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

        std::pair<std::string, double> parseLine(std::string &line);
        int extract_csv();
        void calculateBtc(std::pair<std::string, double> data_input);
        void print_data();

};

#endif