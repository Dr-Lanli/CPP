#include "ScalarConverter.hpp"

int main (int argc, char *argv[])
{
    try
    {
        std::string str(argv[1]);
        ScalarConverter conv;
        conv.convert(str);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}