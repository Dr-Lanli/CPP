#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
}

Cat::~Cat()
{
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other) 
	{
		this->_type = other._type;
	}
	return (*this);
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->_type = other._type;

}
