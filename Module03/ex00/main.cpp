#include "ClapTrap.hpp"

int main (void)
{
    std::cout << "===== Creating ClapTraps =====" << std::endl;
    ClapTrap human("human");
    ClapTrap monster("monster");

    std::cout << "\n===== Testing attack damage =====" << std::endl;
    human.attack("monster");
    monster.takeDamage(human.getAttackDamage());

    monster.attack("human");
    human.takeDamage(monster.getAttackDamage());

    std::cout << "\n===== Testing reparation =====" << std::endl;
    monster.beRepaired(5);
    human.beRepaired(3);

    std::cout << "\n===== Testing max energy =====" << std::endl;
    for (int i = 0; i < 11; i++)  // 8 max, 2 energies used before
        human.attack("monster");

    std::cout << "\n===== Testing Claptrap 0 hp =====" << std::endl;
    monster.takeDamage(100);
    monster.attack("human");   // not working, monster dead
    monster.beRepaired(10);    // not working, monster dead

    std::cout << "\n===== More testing =====" << std::endl;
    std::cout << "human: HP = " << human.getHitPoints() << ", Energy = " << human.getAttackDamage() << std::endl;
    std::cout << "monster:   HP = " << monster.getHitPoints() << ", Energy = " << monster.getAttackDamage() << std::endl;

    std::cout << "\n==========" << std::endl;

	return (0);
}