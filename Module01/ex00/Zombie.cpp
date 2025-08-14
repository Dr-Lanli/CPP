#include "Zombie.hpp"

Zombie::Zombie() : _name("Unnamed")
{
}

Zombie::~Zombie()
{
	std::cout << _name << " has been destroyed" << std::endl;
}

void Zombie::setName(std::string& name)
{
	_name = name;
}

std::string Zombie::getName() const
{
	return (_name);
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}