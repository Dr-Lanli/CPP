#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->_type = other._type;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "Miaou? (but wrong...)" << std::endl;
}
