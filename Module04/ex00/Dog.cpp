#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
}


Dog::~Dog()
{
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &other) 
	{
		this->_type = other._type;
	}
	return (*this);
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->_type = other._type;

}
