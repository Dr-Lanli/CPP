#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	/* data */
public:
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	void highFivesGuys(void);
};




#endif