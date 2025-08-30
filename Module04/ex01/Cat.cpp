#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other) 
	{
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
}

Brain* Cat::getBrain() const 
{ 
	return (_brain); 
}

