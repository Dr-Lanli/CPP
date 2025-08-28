#include "FragTrap.hpp"

int main (void)
{
 	std::cout << "===== Creating ClapTrap / ScavTrap / FragTrap =====" << std::endl;
    ClapTrap basic("Basic");
    ScavTrap guardian("Guardian");
    FragTrap ultimate("Bomultimateber");

    std::cout << "\n===== Testing attack damage =====" << std::endl;
    basic.attack("Guardian");
    guardian.takeDamage(basic.getAttackDamage());

    guardian.attack("ultimate");
    ultimate.takeDamage(guardian.getAttackDamage());

    ultimate.attack("Guardian");
    guardian.takeDamage(ultimate.getAttackDamage());

    std::cout << "\n===== Testing repair =====" << std::endl;
    basic.beRepaired(5);
    guardian.beRepaired(10);
    ultimate.beRepaired(20);

    std::cout << "\n===== Special mode ScavTrap =====" << std::endl;
    guardian.guardGate();

    std::cout << "\n===== Special mode FragTrap =====" << std::endl;
    ultimate.highFivesGuys();

    std::cout << "\n===== Testing copy =====" << std::endl;
    ScavTrap copyGuardian(guardian);
    FragTrap copyUltimate(ultimate);

    ScavTrap assigned("TempScav");
    assigned = guardian;               // opérateur d’assignation

    FragTrap assignedFrag("TempFrag");
    assignedFrag = ultimate;             // opérateur d’assignation

    std::cout << "\n===== Testing limits =====" << std::endl;
    // Vider l'énergie du FragTrap
    for (int i = 0; i < 105; i++)
        ultimate.attack("Guardian");

    // Mettre Basic KO
    basic.takeDamage(500);
    basic.attack("Guardian");  // ne devrait pas marcher
    basic.beRepaired(20);      // ne devrait pas marcher non plus

    std::cout << "\n==========" << std::endl;


	return (0);
}