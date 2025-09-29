#include "Bureaucrat.hpp"

int main ()
{
    /*try
    {
        Bureaucrat worker("jacob", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }*/

    try
    {
        Bureaucrat worker("Elena", 15);
        std::cout << worker << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}