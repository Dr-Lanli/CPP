#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>


int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btc <file>" << std::endl;
        return (1);
    }

    BitcoinExchange btc;
    std::ifstream inputFile(argv[1]);
    if (!inputFile)
    {
        std::cout << "File doesn't exist" << std::endl;
        return (1);
    }
    if (btc.extract_csv() == -1)
        return (1);
    std::string line;

    while (getline (inputFile, line))
    {
        std::pair<std::string, int> data_input;
        data_input = btc.parseLine(line);
        if (data_input.first.empty())
            continue ;
        btc.calculateBtc(data_input);
        //std::cout << line << std::endl;
    }
    //btc.print_data();

    return (0);
}