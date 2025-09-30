#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
    /*try
    {
        Bureaucrat worker("Elena", 15);
        std::cout << worker << std::endl;

        Form form("classic", 5, 5);
        std::cout << form << std::endl;

        worker.signForm(form);
        std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }*/

    try
    {
        Bureaucrat worker("Elena", 15);
        std::cout << worker << std::endl;

        Form form("classic", 25, 25);
        std::cout << form << std::endl;

        worker.signForm(form);
        std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}