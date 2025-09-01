#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &other)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &other) 
	{
		for (size_t i = 0; i < 100; i++)
		{
			this->_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		this->_ideas[i] = other._ideas[i];
	}
}

void Brain::setIdea(int i, const std::string &idea) 
{
    if (i >= 0 && i < 100)
        _ideas[i] = idea;
}

std::string Brain::getIdea(int i) const 
{
    if (i >= 0 && i < 100)
        return (_ideas[i]);
    return ("");
}