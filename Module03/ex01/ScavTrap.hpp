#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
private:

public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	void attack(const std::string& target);
	void guardGate();
};

#endif