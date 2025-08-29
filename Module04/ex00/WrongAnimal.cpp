#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal constructor called with type: " << _type << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->_type = other._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

std::string WrongAnimal::getType() const
{
    return (_type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "Some generic wrong animal sound..." << std::endl;
}
