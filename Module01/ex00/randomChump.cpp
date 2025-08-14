#include "Zombie.hpp"

void Zombie::randomChump(std::string name)
{
	Zombie *zombie = new Zombie;

	zombie->setName(name);
	zombie->announce();
	delete zombie;
}