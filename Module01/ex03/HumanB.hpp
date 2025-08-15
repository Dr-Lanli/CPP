#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>
#include <string.h>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	std::string _weapon;
public:
	HumanB(std::string name);
	~HumanB();
	std::string getName() const;
	void setName(std::string name);
	std::string getWeapon() const;
	void setWeapon(Weapon weapon);
	void attack();
};

#endif