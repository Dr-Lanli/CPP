#include "ScalarConverter.hpp"

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <string>" << std::endl;
        return (1);
    }
    try
    {
        std::string str(argv[1]);
        ScalarConverter::convert(str);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}