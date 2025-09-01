#include "Animal.hpp"

Animal::Animal(std::string type)
{
	std::cout << "Animal constructor called" << std::endl;
	_type = type;
}

Animal::Animal() : _type("")
{
}

Animal::~Animal()
{
}

Animal& Animal::operator=(const Animal &other)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &other) 
	{
		this->_type = other._type;
	}
	return (*this);
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	this->_type = other._type;

}

std::string Animal::getType() const
{
	return(_type);
}

