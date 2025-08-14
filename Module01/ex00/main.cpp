#include "Zombie.hpp"

int main (void)
{
	Zombie zombie;

	Zombie *z1 = zombie.newZombie("first");
	zombie.randomChump("second");
	Zombie *z2= zombie.newZombie("third");

	delete z1;
	delete z2;
	return (0);
}