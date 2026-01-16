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
    std::string line;

    while (getline (inputFile, line))
    {

        btc.parseLine(line);
        std::cout << line << std::endl;
    }

    return (0);
}