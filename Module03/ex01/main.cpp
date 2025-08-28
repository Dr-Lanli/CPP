#include "ScavTrap.hpp"

int main (void)
{
	std::cout << "===== Creating ClapTrap and ScavTrap =====" << std::endl;
    ClapTrap basic("Basic");
    ScavTrap guardian("Guardian");

    std::cout << "\n===== Testing attack damage =====" << std::endl;
    basic.attack("Guardian");
    guardian.takeDamage(basic.getAttackDamage());

    guardian.attack("Basic");
    basic.takeDamage(guardian.getAttackDamage());

    std::cout << "\n===== Testing repairs =====" << std::endl;
    basic.beRepaired(5);
    guardian.beRepaired(10);

    std::cout << "\n===== Special mode ScavTrap =====" << std::endl;
    guardian.guardGate();

    std::cout << "\n===== Copy test =====" << std::endl;
    ScavTrap copyGuardian(guardian); 
    ScavTrap assigned("Temp");
    assigned = guardian;

    std::cout << "\n===== limits test =====" << std::endl;
    for (int i = 0; i < 55; i++)
        guardian.attack("Basic");

    basic.takeDamage(500);
    basic.attack("Guardian");  // should not work
    basic.beRepaired(20);      // should not work

    std::cout << "\n==========" << std::endl;


	return (0);
}