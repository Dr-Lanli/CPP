#include "Zombie.hpp"

int main (void)
{
    Zombie tmp;

    std::cout << "=== Test 1 : 3 zombies normaux ===" << std::endl;
    Zombie *horde1 = tmp.zombieHorde(3, "Walker");
    delete[] horde1;

    std::cout << "\n=== Test 2 : 1 zombie ===" << std::endl;
    Zombie *horde2 = tmp.zombieHorde(1, "Solo");
    delete[] horde2;

    std::cout << "\n=== Test 3 : 0 zombies ===" << std::endl;
    Zombie *horde3 = tmp.zombieHorde(0, "Nobody");
    delete[] horde3;

    std::cout << "\n=== Test 4 : nom vide ===" << std::endl;
    Zombie *horde4 = tmp.zombieHorde(2, "");
    delete[] horde4;

    std::cout << "\n=== Test 5 : nom long / caractères spéciaux ===" << std::endl;
    Zombie *horde5 = tmp.zombieHorde(2, "💀💀💀--Zombie_boss#789--💀💀💀");
    delete[] horde5;

    return (0);
}