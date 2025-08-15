#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::~HumanB()
{
}

std::string HumanB::getName() const
{
	return (_name);
}

void HumanB::setName(std::string name)
{
	_name = name;
}

std::string HumanB::getWeapon() const
{
	return (_weapon);
}

void HumanB::setWeapon(Weapon weapon)
{
	std::string type;

	type = weapon.getType();
	_weapon = type;
}

void HumanB::attack()
{
	std::cout << _name << " attack with their " << _weapon << std::endl;
}