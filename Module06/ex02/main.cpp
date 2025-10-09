#include "Base.hpp"

int main (void)
{
    srand(time(0));
    std::cout << "Test with pointer" << std::endl;
    try
    {
        Base *base = Base::generate();
        Base::identify(base);
        delete base;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Test with reference" << std::endl;
    try
    {
        Base *base = Base::generate();
        Base::identify(*base);
        delete base;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Test with nullptr (should not print)" << std::endl;
    try
    {
        Base* nullBase = NULL;
        Base::identify(nullBase);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}